/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:12 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 20:31:48 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_map_size(const char *path)
{
	int		fd;
	char	c;
	int		mapsize;

	printf("ft_mapsize");
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map Error", 10);
		close(fd);
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
	char	*arr;

	printf("ft_getmap");
	arr = malloc(sizeof(char) * ft_map_size(path));
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

struct s_map ft_stfill(char	*mapstring)
{
	int		i;
	t_map	info;
	int		colcount;

	i = 0;
	printf("ft_stfill");
	colcount = 0;
	info.rows = 0;
	while (mapstring[i] != '\n')
	{
		if (mapstring[i] >= '0' && mapstring[i] <= '9')
		{
			info.rows = (info.rows * 10) + mapstring[i] -'0';
			i++;
		}
		info.empty = mapstring[i + 1];
		info.obstacle = mapstring[i + 2];
		info.full = mapstring[i + 3];
	}
	while (mapstring[i] != '\0')
	{
		if (mapstring[i] == '\n')
			info.rows++;
		i++;
		colcount++;
	}
	info.cols = colcount / info.rows;
	return (info);
}

char	*ft_finalmap(char *mapstring)
{
	char	*out;
	int		c;
	int		ic;
	t_map	info;

	c = 0;
	ic = 0;
	printf("ft_finalmap");
	out = malloc(sizeof(char *) * (info.rows * info.cols));
	if (!out)
		return (NULL);
	while (mapstring[c] != '\n')
		c++;
	while (mapstring[c] != '\0')
		out[ic++] = mapstring[c++];
	out[ic] = '\0';
	return (out);
}

char	*ft_maphandle(const char	*path)
{
	char	*tempstr;
	char	*final;
	t_map	info;

	printf("ft_maphandle");
	tempstr = malloc(sizeof(char *) * ft_map_size(path));
	if (!tempstr)
		return (NULL);
	tempstr = ft_getmap(path);
	ft_stfill(tempstr);
	final = malloc(sizeof(char *) * (info.rows * info.cols));
	if (!final)
		return (NULL);
	final = ft_finalmap(ft_getmap(path));
	return (final);
	free (tempstr);
}
