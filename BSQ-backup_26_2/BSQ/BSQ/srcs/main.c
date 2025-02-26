/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:27:30 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 19:25:34 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// void	ft_mapfill(int **map, t_map *info)
// {
// 	int		a;
// 	int		b;
// 	char	*out;

// 	out = malloc(sizeof(char) * (info->cols + 2));
// 	if (!out)
//         return ;

// 	a = 0;
// 	while (a < info->rows)
// 	{
// 		b = 0;
// 		while (b < info->cols)
// 		{
// 			if (map[a][b] == 0)
// 				out[b] = info->full;
// 			else if (map[a][b] >= 1)
// 				out[b] = info->obstacle;
// 			else if(map[a][b] == -1)
// 				out[b] = info->empty;
// 			b++;
// 		}
// 		out[b] = '\n';
// 		out[b + 1] = '\0';

// 		ft_putstr(out);

// 		a++;
// 	}
// 	free(out);
// }

void	ft_mapfill(int **map, t_map *info)
{
	int		a;
	int		b;
	int		c;
	char	*out;

	a = -1;
	if (!(out = malloc(sizeof(char *) * info->rows)))
		return ;
	while (++a < (info->cols - 1))
	{
		b = -1;
		c = 0;
		if (map[a][b] == -1)
			out[c++] = info->full;
		else if (map[a][b] == 1)
			out[c++] = info->obstacle;
		else
			out[c++] = info->empty;
	}
	out[c++] = '\n';
	out[c] = '\0';
	ft_putstr(out);
}

int main(int argc, char **argv)
{
    char	*originalmap;
    int		**convmap;
	t_map	*info;

    if (argc != 2)
    {
        write(1, "Usage: ./bsq mapfile\n", 21);
        return (1);
    }

	info->data = read_map(argv[1], *info);

	originalmap = array_to_string(info->data, info->rows);

    if (!originalmap)
    {
        write(1, "map error\n", 10);
		free(originalmap);
        return (1);
    }

    convmap = ft_mapconvertor(originalmap, info);
    if (!convmap)
    {
        write(1, "map error\n", 10);
        // free_map(info, info->rows);
        return (1);
    }

    ft_mapfill(ft_square(convmap, info), info);


    return (0);
}

