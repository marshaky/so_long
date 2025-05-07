/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:25:23 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/07 05:26:05 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE 64

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	render_map(t_game *game)
{
	for (int y = 0; game->map[y]; y++)
	{
		for (int x = 0; game->map[y][x]; x++)
		{
			char c = game->map[y][x];
			if (c == '1')
				put_image(game, game->img_wall, x, y);
			else
				put_image(game, game->img_floor, x, y);
			if (c == 'P')
				put_image(game, game->img_player, x, y);
			else if (c == 'C')
				put_image(game, game->img_collectable, x, y);
			else if (c == 'E')
				put_image(game, game->img_exit, x, y);
		}
	}
}
