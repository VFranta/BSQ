/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranta <vfranta@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:47 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 19:23:18 by vfranta          ###   ########.fr       */
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


char	*ft_maphandle(const char	*path);

#endif


// typedef struct s_map
// {
// 	char	**data;
// 	char	empty;
// 	char	obstacle;
// 	char	full;
// 	int		size;//maybe not needed?
// 	int		rows;
// 	int		cols;
// }	t_map;

// typedef struct	s_find_loc
// {
// 	int	x;
// 	int	y;
// 	int	loc;
// }	t_find_loc;

// //main.c
// void	ft_mapfill(int **map, t_map *info);
// //new_logic.c
// void	ft_find_sq(int **map, t_find_loc *best);
// int	**ft_mapconvertor(char *originalmap, t_map *info);
// int	**ft_square(int **map, t_map *info);
// //tools.c
// int	ft_min(int **map, int i, int j);
// void	ft_putstr(char *str);
// int		ft_strlen(char *str);
// char	*ft_strcat(char *dest, char *src);
// //read_map.c
// char	**allocate_map(int y, int x);
// char	**read_map(const char *filename, t_map info);
// void	parse_map(char *ptr, t_map *info, int *y, int *x);
// void	fill_map(char *ptr, t_map *info);
// void	free_map(t_map *info);
// char	*array_to_string(char **array, int rows);
