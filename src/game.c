/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:13:28 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/21 03:29:51 by marshaky         ###   ########.fr       */
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
	game->move_status = 0;
	game->coin_count = count_coins(game);
	game->moves = 0;
	game->endgame = 0;
}

void	init_imgs(t_game *game)
{
	game->img_wall = ft_make_xpm_img(game, "wall.xpm");
	game->img_floor = ft_make_xpm_img(game, "ground.xpm");
	game->img_exit = ft_make_xpm_img(game, "exit.xpm");
	game->img_coin = ft_make_xpm_img(game, "star0.xpm");
	game->img_player = ft_make_xpm_img(game, "rkirby0.xpm");
}

void	start_game(t_game *game)
{
	draw_init(game);
	ft_printf("\033[1;33m== Start Game ==\033[0m\n");
}

int	close_game(t_game *game)
{
	ft_printf("END\n");
	free_split(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	count_coins(t_game *game)
{
	int	x;
	int	y;

	game->coin_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->coin_count++;
			x++;
		}
		y++;
	}
	return (game->coin_count);
}
