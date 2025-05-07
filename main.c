/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:30:21 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/07 05:35:19 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &(int){0}, &(int){0});
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &(int){0}, &(int){0});
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &(int){0}, &(int){0});
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &(int){0}, &(int){0});
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, "textures/collectable.xpm", &(int){0}, &(int){0});
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: %s map.ber\n", argv[0]), 1);
	game.map = read_map(argv[1]); // Функция из предыдущего шага
	if (!game.map)
		return (ft_printf("Error: failed to load map\n"), 1);
	game.height = 0;
	while (game.map[game.height])
		game.height++;
	game.width = ft_strlen(game.map[0]);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	init_images(&game);
	render_map(&game);

	mlx_loop(game.mlx);
	return (0);
}
