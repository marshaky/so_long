/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:16:10 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/21 03:18:25 by marshaky         ###   ########.fr       */
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
		throw_error("XPM Error : check ASSET_PATH or fileName");
	}
	else if (!(width == game->img_width && height == game->img_height))
		throw_error("TILE SIZE Error : incorrect tile size");
	return (img);
}

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	destroy_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_coin);
	mlx_destroy_image(game->mlx, game->img_exit);
}
