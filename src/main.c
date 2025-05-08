/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:30:21 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/08 04:47:20 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &(int){0}, &(int){0});
	if (!game->img_wall) ft_printf("Failed to load wall.xpm\n");

	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &(int){0}, &(int){0});
	if (!game->img_floor) ft_printf("Failed to load floor.xpm\n");

	game->img_player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &(int){0}, &(int){0});
	if (!game->img_player) ft_printf("Failed to load player.xpm\n");

	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &(int){0}, &(int){0});
	if (!game->img_exit) ft_printf("Failed to load exit.xpm\n");

	game->img_collectable = mlx_xpm_file_to_image(game->mlx, "./textures/collectable.xpm", &(int){0}, &(int){0});
	if (!game->img_collectable) ft_printf("Failed to load collectable.xpm\n");

	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectable)
	{
		ft_printf("Error: failed to load one or more textures\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_printf("🔵 START MAIN\n");

	if (argc != 2)
		return (ft_printf("Usage: %s map.ber\n", argv[0]), 1);

	game.map = read_map(argv[1]);
	if (!game.map)
		return (ft_printf("❌ Error: failed to load map\n"), 1);
	ft_printf("✅ Map loaded from %s\n", argv[1]);

	game.height = 0;
	while (game.map[game.height])
		game.height++;
	game.width = ft_strlen(game.map[0]);
	ft_printf("🧭 Map dimensions: %d x %d tiles\n", game.width, game.height);

	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("❌ mlx_init failed\n"), 1);
	ft_printf("✅ mlx_init OK\n");

	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	if (!game.win)
		return (ft_printf("❌ mlx_new_window failed\n"), 1);
	ft_printf("✅ Window created\n");

	init_images(&game);
	render_map(&game);
	ft_printf("🖼  Map rendered!\n");

	mlx_loop(game.mlx);
	ft_printf("🔁 Loop ended (should not happen normally)\n");
	return (0);
}