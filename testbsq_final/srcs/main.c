/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:11 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 20:36:00 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"


void	ft_mapfill(int **map)
{
	int		a;
	int		b;
	int		c;
	char	*out;
	t_map	info;

	a = -1;
	if (!(out = malloc(sizeof(char *) * (info.rows))))
		return ;
	while (++a < (info.cols - 1))
	{
		b = -1;
		c = 0;
		if (map[a][b] == -1)
			out[c++] = info.full;
		else if (map[a][b] == 1)
			out[c++] = info.obstacle;
		else
			out[c++] = info.empty;
	}
	out[c++] = '\n';
	out[c] = '\0';
	ft_putstr(out);
	free(out);
}

int main(int argc, char **argv)
{
	int		c;
	int		**ptr;

	c = 1;
	if (argc < 2)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	ptr = ft_mapconvertor(ft_maphandle(argv[c]));
	if (!ptr)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	while (c < argc)
	{
		printf("before mapfill");
		ft_mapfill(ptr);
		c++;
	}
	free(ptr);
	return (0);
}
