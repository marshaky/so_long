/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:30:21 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/11 03:21:01 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		throw_error("UsageError : ./so_long map.ber\n");

	game.img_width = 64;
	game.img_height = 64;
	game.player_cord.x = -1;
	game.player_cord.y = -1;
	valid_extension(argv[1]);
	read_map(&game, argv[1]);
	count_components(&game);
	count_coins(&game);
	init_window(&game);
	init_imgs(&game);
	start_game(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

