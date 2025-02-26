#include "ft.h"

char **allocate_map(int rows, int cols)
{
    char **info;
    int i = 0;

    info = malloc(sizeof(char *) * rows);
    if (!info)
        return (NULL);
    while (i < rows)
    {
        info[i] = malloc(cols + 1);
        if (!info[i])
            return (NULL);
        i++;
    }
    return (info);
}

void parse_header(char **ptr, t_map *info, int *rows, int *cols)
{
    while (**ptr >= '0' && **ptr <= '9')
        (*ptr)++;
    info->empty = *(*ptr)++;
    info->obstacle = *(*ptr)++;
    info->full = *(*ptr)++;
    (*ptr)++;

    *cols = 0;
    while ((*ptr)[*cols] && (*ptr)[*cols] != '\n')
	{
		(*cols)++;
		info->cols = *cols;
	}

    *rows = 0;
    while (**ptr)
    {
        if (**ptr == '\n')
            (*rows)++;
        (*ptr)++;
		info->rows = *rows;
    }
}

void fill_map(char **info, const char *ptr, int rows, int cols)
{
    int i = 0;
	int j;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            info[i][j] = *ptr++;
            j++;
        }
        info[i][cols] = '\0';
        if (*ptr == '\n')
            ptr++;
        i++;
    }
}

char **read_map(const char *filename, t_map info)
{
    int fd, bytes, rows, cols;
    char buffer[4096], *ptr;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    bytes = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    if (bytes <= 0)
        return (NULL);
    buffer[bytes] = '\0';

    ptr = buffer;
    parse_header(&ptr, &info, &rows, &cols);
    info.data = allocate_map(rows, cols);
    if (!info.data)
        return (NULL);
    fill_map(info.data, ptr, rows, cols);
    return (info.data);
}

void free_map(t_map *info, int rows)
{
    int i = 0;
    while (i < rows)
    {
        free(info->data[i]);
        i++;
    }
    free(info->data);
}

