/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:01:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/21 03:15:16 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tiles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				ft_put_img(game, game->img_wall,
					x * game->img_width, y * game->img_height);
			else
				ft_put_img(game, game->img_floor,
					x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
			{
				ft_put_img(game, game->img_exit,
					x * game->img_width, y * game->img_height);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player_cord.x;
	y = game->player_cord.y;
	ft_put_img(game, game->img_player,
		x * game->img_width, y * game->img_height);
}

void	draw_init(t_game *game)
{
	init_imgs(game);
	draw_tiles(game);
	draw_animate_collect(game);
	draw_exit(game);
	draw_player(game);
	destroy_imgs(game);
}

void	draw_animate_collect(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				ft_put_img(game, game->img_coin,
					x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}
