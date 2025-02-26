/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:12 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 19:21:39 by vfranta          ###   ########.fr       */
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

	arr = malloc(sizeof(char) * ft_map_size(path));
	if (!arr)
		exit (NULL);
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
	colcount = 0;
	info.rows = 0;
	while (mapstring[i] != '\n')
	{
		if (mapstring[c] >= '0' && mapstring[c] <= '9')
		{
			info.rows = (info.rows * 10) + mapstring[c] -'0';
			c++;
		}
		info.empty = mapstring[c + 1];
		info.obstacle = mapstring[c + 2];
		info.full = mapstring[c + 3;]
	}
	while (mapstring != '\0')
	{
		if (mapstring[c] == '\n')
			info.rows++;
		c++;
		colcount++;
	}
	info.cols = colcount / &info.rows;
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
	out = malloc(sizeof(char *) * (&info->rows * & info->cols));
	if (!out)
		exit (NULL);
	while (mapstring[c] != "\n")
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

	tempstr = malloc(sizeof(char *) * ft_map_size(path));
	if (!tempstr)
		exit ();
	tempstr = ft_getmap(path);
	ft_stfill(tempstr);
	final = malloc(sizeof(char *) * (info->row * info->cols));
	if (!final)
		exit ();
	final = ft_finalmap(ft_getmap(path));
	return (final);
	free (tempstr);
}
