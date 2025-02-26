/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:12 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/26 12:50:29 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_map_size(const char *path)
{
	int		fd;
	char	c;
	int		mapsize;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	mapsize = 0;
	while (read(fd, &c, 1))
	{
		mapsize++;
	}
	close(fd);
	return (mapsize);
}

char	*ft_getmap(const char *path)
{
	int		fd;
	char	c;
	int		in;
	int		size;
	char	*arr;

	size = ft_map_size(path);
	if (size <= 0)
		return (NULL);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(arr);
		return (NULL);
	}
	in = 0;
	while (read(fd, &c, 1))
	{
		arr[in] = c;
		in++;
	}
	arr[in] = '\0';
	close(fd);
	return (arr);
}

t_map	ft_stfill(char *mapstring)
{
	int		i;
	t_map	info;
	int		colcount;

	i = 0;
	colcount = 0;
	info.rows = 0;
	while (mapstring[i] >= '0' && mapstring[i] <= '9')
	{
		info.rows = (info.rows * 10) + (mapstring[i] - '0');
		i++;
	}
	if (!mapstring[i] || !mapstring[i + 1] || !mapstring[i + 2])
	{
		info.rows = -1;
		return (info);
	}
	info.empty = mapstring[i];
	info.obstacle = mapstring[i + 1];
	info.full = mapstring[i + 2];
	i += 3;
	if (mapstring[i] != '\n')
	{
		info.rows = -1;
		return (info);
	}
	i++;
	while (mapstring[i] != '\n' && mapstring[i] != '\0')
	{
		colcount++;
		i++;
	}
	info.cols = colcount;
	return (info);
}

char	*ft_finalmap(char *mapstring, t_map info)
{
	char	*out;
	int		c;
	int		ic;
	int		map_length;

	c = 0;
	ic = 0;
	map_length = (info.rows * info.cols) + info.rows - 1;
	out = malloc(map_length + 1);
	if (!out)
		return (NULL);
	while (mapstring[c] != '\n' && mapstring[c] != '\0')
		c++;
	if (mapstring[c] == '\n')
		c++;
	while (mapstring[c] != '\0' && ic < map_length)
		out[ic++] = mapstring[c++];
	return (out);
}

char	*ft_maphandle(const char *path)
{
	char	*tempstr;
	char	*final;
	t_map	info;

	tempstr = ft_getmap(path);
	if (!tempstr)
		return (NULL);
	info = ft_stfill(tempstr);
	if (info.rows <= 0 || info.cols <= 0)
	{
		free(tempstr);
		return (NULL);
	}
	final = ft_finalmap(tempstr, info);
	if (!final)
	{
		free(tempstr);
		return (NULL);
	}
	free(tempstr);
	return (final);
}
