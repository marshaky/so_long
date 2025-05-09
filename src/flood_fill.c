/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:40:53 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 05:41:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

int	is_reachable(char **map)
{
	int		y = 0;
	int		x;
	char	**copy;
	int		found_c = 0, found_e = 0;

	copy = ft_split_map(map);
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
			{
				fill(copy, x, y);
				break ;
			}
			x++;
		}
		y++;
	}

	y = -1;
	while (copy[++y])
	{
		x = -1;
		while (copy[y][++x])
		{
			if (copy[y][x] == 'C')
				found_c++;
			if (copy[y][x] == 'E')
				found_e++;
		}
		free(copy[y]);
	}
	free(copy);
	return (found_c == 0 && found_e == 0);
}
