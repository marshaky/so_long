/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:21:02 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 05:36:36 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	if (game->map[ny][nx] == '1')
		return ;
	if (game->map[ny][nx] == 'E')
	{
		if (game->collected_coins == game->total_coins)
			exit(0);
		else
			return ;
	}
	if (game->map[ny][nx] == 'C')
		game->collected_coins++;
	game->map[game->player_y][game->player_x] = '0';
	game->map[ny][nx] = 'P';
	game->player_x = nx;
	game->player_y = ny;
	game->move_count++;
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		ft_printf("👋 Exit\n");
		exit(0);
	}
	else if (keycode == 0)
		move_player(game, -1, 0);
	else if (keycode == 1)
		move_player(game, 0, 1);
	else if (keycode == 2)
		move_player(game, 1, 0);
	else if (keycode == 13)
		move_player(game, 0, -1);
	return (0);
}
