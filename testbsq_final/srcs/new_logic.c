/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:54:54 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 20:30:35 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

struct s_find_loc	ft_find_sq(int **map)
{
	int			row;
	int			col;
	t_find_loc	best;

	printf("ft_find_sq");
	row = best.y - best.loc + 1;
	col = best.x - best.loc + 1;
	while (row <= best.y)
	{

		while (col <= best.x)
		{
			map[row][col] = -1;
			col++;
		}
		col = best.x - best.loc + 1;
		row++;
	}
	return (best);
}

int **ft_square(int **map)
{
	int			i;
	int			j;
	t_map		info;
	t_find_loc	best = {0, 0, 0};

	i = 1;
	printf("ft_square");
	while (i < info.rows)
	{
		j = 1;
		while (j < info.cols)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = ft_min(map, i, j);
				if (map[i][j] > best.loc) {
					best.x = j;
					best.y = i;
					best.loc = map[i][j];
				}
			}
			j++;
		}
		i++;
	}
	ft_find_sq(map);
	return (map);
}
//works fine

int	**ft_mapconvertor(char *originalmap)
{
	int		c;
	int		ic;
	int		i;
	int		**convmap;
	t_map	info;

	i = 0;
	ic = 0;
	c = 0;
	printf("mapconvertor");
	convmap = (int **)malloc(sizeof(int *) * info.rows);
	if (!convmap)
		return (0);
	while (i < info.rows)
	{
		convmap[i] = (int *)malloc(sizeof(int) * info.cols);
		if (!convmap[i])
		{
		while (i > 0)
			{
				i--;
				free(convmap[i]);
			}
			free(convmap);
			return NULL;
		}
		i++;
	}
	i = 0;
	while (originalmap)
	{
		if (*originalmap == '\n')
		{
			c++;
			ic = 0;
		} else if (*originalmap == info.empty)
		{
			convmap[c][ic++] = 1;
		}
		else if (*originalmap == info.obstacle)
		{
			convmap[c][ic++] = 0;
		}
		originalmap++;
	}
	return convmap;
}

