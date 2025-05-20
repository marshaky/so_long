/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:57:01 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/21 03:17:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		handle_location(game, 0, -1);
	else if (keycode == KEY_S)
		handle_location(game, 0, 1);
	else if (keycode == KEY_A)
		handle_location(game, -1, 0);
	else if (keycode == KEY_D)
		handle_location(game, 1, 0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else
		move_key_hook(keycode, game);
	return (0);
}

int	loop_hook(t_game *game)
{
	if (!game->coin_count)
		show_door(game);
	if (!game->endgame)
	{
		draw_init(game);
	}
	return (0);
}
