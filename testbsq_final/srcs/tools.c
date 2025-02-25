/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emustafi <emustafi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:54 by vfranta           #+#    #+#             */
/*   Updated: 2025/02/25 18:10:22 by emustafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int ft_min(int **map, int i, int j)
{
    int	up;
    int	left;
    int	diagonal;
	int	min_val;

	up = map[i - 1][j];
	left = map[i][j - 1];
	diagonal = map[i - 1][j - 1];
	if (map[i][j] == 0)
	{
		return 0;
	}
	if (i > 0 && j > 0 && up != 0 && left != 0 && diagonal != 0)
	{
		min_val = up;
        if (left < min_val) min_val = left;
        if (diagonal < min_val) min_val = diagonal;
        return min_val + 1;
    }
    return 1;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
    int i;
	
	i = 0;
    while (str[i])
        i++;
    return (i);
}


// char	*ft_strcat(char *dest, char *src)
// {
// 	char	*temp;

// 	temp = dest;
// 	while (*dest)
// 	{
// 		dest++;
// 	}
// 	while (*src)
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 	}
// 	*dest = '\0';
// 	return (temp);
// }