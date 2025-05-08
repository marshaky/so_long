/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:25:23 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/08 04:37:49 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x, y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			char tile = game->map[y][x];

			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 64, y * 64);
			// if (tile == '1')
			// 	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
			if (tile == '1')
			{
				int color = 0x00FF00;
				mlx_pixel_put(game->mlx, game->win, x * 64 + 10, y * 64 + 10, color);
			}
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64, y * 64);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectable, x * 64, y * 64);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);

			x++;
		}
		y++;
	}
}