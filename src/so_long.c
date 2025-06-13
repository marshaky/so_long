/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:30:21 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/12 19:18:08 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_door(t_game *game)
{
	if (game->map[game->exit.y][game->exit.x] == '0')
		game->map[game->exit.y][game->exit.x] = 'E';
}

void	save_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
				game->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

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
	validate_reachability(&game);
	save_exit(&game);
	count_coins(&game);
	init_window(&game);
	start_game(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
