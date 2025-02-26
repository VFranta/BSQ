/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emustafi <emustafi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:18:23 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 12:21:24 by emustafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_copymap(int	**arrmap, struct s_map map)
{
	int	**mapclone;
	int	x;//colloms
	int	y;//rows

	x = 0;
	y = 0;
	mapclone = (int **)malloc(sizeof(int *) * map.rows);
	while (y < map.rows)
	{
		mapclone[y] = (int *)malloc(sizeof(int *) * map.cols)
		y++;
	}
	y = 0;
	while (y < map.rows)
	{
		x = 0;
		while (x < map.cols)
		{
			mapclone[y][x] = arrmap[y][x];
			x++;
		}
		y++;
	}
	ft_findbiggest(map.cols, map.rows, mapclone);
	y = 0;
	while (y < map.rows)
	{
		free(mapclone[y]);
		y++;
	}
	free(mapclone);
}

int	*ft_findbiggest(int x, int y, int **m_c)//m_c == map clone
{
	int	i;//colloms
	int	j;//lines
	int	result;

	i = 1;
	j = 1;
	while (j < y)
	{
		while (i < x)
		{
			if (arrmap[j][i] > 0)
				m_c[j][i] = 1 + ft_min(m_c[j][i-1], m_c[j-1][i], m_c[j-1][i-1]);
			i++;
		}
		if (m_c[j][i] > result)
			result = m_c[j][i];
		j++;
	}
	return (result);
}
