/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:47 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/26 12:39:47 by vfranta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h> //remove in final version just 4 tests

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_find_loc
{
	int	x;
	int	y;
	int	loc;
}	t_find_loc;

void				ft_putstr(char *str);
void				ft_mapfill(int **map, t_map	*info);
int					ft_map_size(const char *path);
int					**ft_square(int **map, t_map *info);
int					**ft_mapconvertor(char *originalmap, t_map *info);
int					ft_min(int **map, int i, int j);
int					ft_strlen(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_getmap(const char *path);
char				*ft_finalmap(char *mapstring, t_map info);
char				*ft_maphandle(const char *path);
struct s_map		ft_stfill(char *mapstring);
struct s_find_loc	ft_find_sq(int **map, t_find_loc best);

#endif
