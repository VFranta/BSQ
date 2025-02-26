/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:11 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/26 11:23:08 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_mapfill(int **map, t_map	*info)
{
	int		a;
	int		b;
	int		c;
	char	*out;

	a = 0;
	while (a < (info->rows))
	{
		if (!(out = malloc(sizeof(char *) * (info->cols + 2))))
			return ;
		b = 0;
		c = 0;
		while (b < info->cols)
		{
			if (map[a][b] == -1)
				out[c++] = info->full;
			else if (map[a][b] == 1)
				out[c++] = info->obstacle;
			else
				out[c++] = info->empty;
			b++;
		}
		out[c++] = '\n';
		out[c] = '\0';
		ft_putstr(out);
		free(out);
		a++;
	}

}

int main(int argc, char **argv)
{
	int		c;
	int		**ptr;
	char	*map_str;
	t_map	info;

	if (argc < 2)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	c = 1;

	while (c < argc)
	{
		map_str = (ft_maphandle(argv[c]));
		if (!map_str)
		{
			write(1, "map error\n", 10);
			return (1);
		}
		info = ft_stfill(ft_getmap(argv[c]));
		ptr = ft_mapconvertor(map_str, &info);
		free(map_str);
		if (!ptr)
			return (1);
		ptr = ft_square(ptr, &info);
		if (!ptr)
			return (1);
		ft_mapfill(ptr, &info);
		for (int i = 0; i < info.rows; i++)
			free(ptr[i]);
		free(ptr);
		c++;
	}
	return (0);
}
