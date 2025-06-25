/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:16:10 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/25 19:10:06 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_make_xpm_img(t_game *game, char *xpm_file)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	path = ft_strjoin(ASSET_PATH, xpm_file);
	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	free(path);
	if (!img)
	{
		free(img);
		ft_printf("fileName: %s\n", xpm_file);
		ft_clean(game);
		throw_error("XPM Error : check ASSET_PATH or fileName\n");
	}
	else if (!(width == game->img_width && height == game->img_height))
	{
		free_split(game->map, game->map_height);
		throw_error("TILE SIZE Error : incorrect tile size");
	}
	return (img);
}

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	destroy_imgs(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

void	ft_clean(t_game *game)
{
	destroy_imgs(game);
	if (game->map)
		free_split(game->map, game->map_height);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
