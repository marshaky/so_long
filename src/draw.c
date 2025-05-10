/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:01:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/10 05:58:14 by marshaky         ###   ########.fr       */
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
				ft_put_img(game, game->img_wall, x * game->img_width, y * game->img_height);
			else
				ft_put_img(game, game->img_floor, x * game->img_width, y * game->img_height);
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
				if (game->coin_count == 0)
					ft_put_img(game, game->img_exit, x * game->img_width, y * game->img_height);
				else
					ft_put_img(game, game->img_floor, x * game->img_width, y * game->img_height);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	x = game->player_cord.x;
	int	y = game->player_cord.y;

	ft_put_img(game, game->img_player, x * game->img_width, y * game->img_height);
}

void	draw_init(t_game *game)
{
	draw_tiles(game);
	draw_animate_collect(game);
	draw_animate_player(game);
	draw_exit(game);
	draw_player(game);
}

void	draw_animate_player(t_game *game)
{
	if (game->move_status == RIGHT)
		game->player_cord.x += 1;
	else if (game->move_status == LEFT)
		game->player_cord.x -= 1;
	else if (game->move_status == TOP)
		game->player_cord.y -= 1;
	else if (game->move_status == BOTTOM)
		game->player_cord.y += 1;
	else
		return ;

	ft_put_img(game, game->img_floor,
		game->player_cord.x * game->img_width,
		game->player_cord.y * game->img_height);
	ft_put_img(game, game->img_player,
		game->player_cord.x * game->img_width,
		game->player_cord.y * game->img_height);

	game->moves++;
	game->move_status = NONE;
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
				ft_put_img(game, game->img_coin, x * game->img_width, y * game->img_height);
			x++;
		}
		y++;
	}
}
