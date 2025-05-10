/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:15:01 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/11 03:15:10 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(t_game *game, int x, int y)
{
	int	blocked = 0;

	if (game->map[y - 1][x] == '1') blocked++;
	if (game->map[y + 1][x] == '1') blocked++;
	if (game->map[y][x - 1] == '1') blocked++;
	if (game->map[y][x + 1] == '1') blocked++;

	return (blocked == 4);
}

void	check_surrounded(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->map_height - 1)
	{
		x = 1;
		while (x < game->map_width - 1)
		{
			if (game->map[y][x] == 'P' || game->map[y][x] == 'C' || game->map[y][x] == 'E')
			{
				if (is_surrounded(game, x, y))
					throw_error("ComponentError: Component is trapped by walls\n");
			}
			x++;
		}
		y++;
	}
}
