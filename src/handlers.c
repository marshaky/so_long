/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:56:04 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/13 01:56:28 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_collect(t_game *game)
{
	int	x;
	int	y;

	x = game->player_cord.x;
	y = game->player_cord.y;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->coin_count--;
	}
}

void	handle_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->player_cord.x;
	y = game->player_cord.y;
	if (game->map[y][x] == 'E' && game->coin_count == 0)
	{
		ft_printf("🎉 You win in %d moves!\n", game->moves);
		close_game(game);
	}
}

void	handle_location(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_cord.x + dx;
	new_y = game->player_cord.y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	game->player_cord.x = new_x;
	game->player_cord.y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->coin_count--;
	}
	handle_exit(game);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				if (found)
					throw_error("ComponentError : more than one player\n");
				game->player_cord.x = x;
				game->player_cord.y = y;
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found)
		throw_error("ComponentError : no player on the map\n");
}

void	count_components(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map_height)
	{
		valid_wall(game, y);
		x = 0;
		while (x < game->map_width)
		{
			c = game->map[y][x];
			check_component(game, c, x, y);
			x++;
		}
		y++;
	}
	if (game->player_cord.x == -1)
		throw_error("ComponentError : player not found\n");
	if (game->coin_count < 1)
		throw_error("ComponentError : no coins on map\n");
	if (game->exit_flag < 1)
		throw_error("ComponentError : no exit on map\n");
	if (game->exit_flag > 1)
		throw_error("ComponentError : more than one exit\n");
}
