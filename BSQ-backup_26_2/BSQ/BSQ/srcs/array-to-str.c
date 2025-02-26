#include "ft.h"

char *array_to_string(char **array, int rows)
{
    int total_length = 0;
    int i = 0;
    char *result;
    char *ptr;

    while (i < rows)
    {
        total_length += ft_strlen(array[i]) + 1;
        i++;
    }

    result = malloc(total_length + 1);
    if (!result)
        return (NULL);

    ptr = result;
    i = 0;
    while (i < rows)
    {
        while (*array[i])
            *ptr++ = *array[i]++;
        
        if (i < rows - 1)
            *ptr++ = '\n';
        i++;
    }
    *ptr = '\0';

    return result;
}