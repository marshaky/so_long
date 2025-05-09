/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:30:21 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 06:01:45 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &(int){0}, &(int){0});
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/ground.xpm", &(int){0}, &(int){0});
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &(int){0}, &(int){0});
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/exit.xpm", &(int){0}, &(int){0});
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"./assets/star0.xpm", &(int){0}, &(int){0});
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectable)
	{
		ft_printf("Error: failed to load one or more textures\n");
		exit(1);
	}
}
static void	find_player_and_coins(t_game *game)
{
	int	x;
	int	y;

	game->total_coins = 0;
	game->collected_coins = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				game->total_coins++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: %s map.ber\n", argv[0]), 1);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (ft_printf("Error: failed to load map\n"), 1);
	if (!is_reachable(game.map))
		return (ft_printf("❌ Map is not solvable\n"), 1);
	game.height = 0;
	while (game.map[game.height])
		game.height++;
	game.width = ft_strlen(game.map[0]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			game.width * 64, game.height * 64, "so_long");
	init_images(&game);
	find_player_and_coins(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
