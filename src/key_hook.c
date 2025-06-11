/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:57:01 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/11 17:20:38 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		handle_location(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_location(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_location(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		handle_location(game, 1, 0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
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
