/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:13:28 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/10 05:49:46 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map_width;
	y = game->map_height;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * x, 64 * y, "KIRBY");
	game->move_status = NONE;
	game->coin_count = 0;
	game->moves = 0;
	game->endgame = 0;
	game->player_cord.x = -1; 
	game->player_cord.y = -1;
}

void	init_imgs(t_game *game)
{
	game->img_wall = ft_make_xpm_img(game, "wall.xpm");
	game->img_floor = ft_make_xpm_img(game, "ground.xpm");
	game->img_exit = ft_make_xpm_img(game, "exit.xpm");
	game->img_coin = ft_make_xpm_img(game, "star0.xpm");
	game->img_player = ft_make_xpm_img(game, "player.xpm");
}

void	init_game(t_game *game)
{
	draw_init(game);
}

void	start_game(t_game *game)
{
	init_game(game);
	printf("\033[1;33m== Start Game ==\033[0m\n");
}

int	close_game(t_game *game)
{
	printf("END\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
