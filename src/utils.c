/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:17:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/13 01:55:02 by marshaky         ###   ########.fr       */
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

void	load_images(t_game *game)
{
	game->img_floor = ft_make_xpm_img(game, "floor.xpm");
	game->img_wall = ft_make_xpm_img(game, "wall.xpm");
	game->img_player = ft_make_xpm_img(game, "player.xpm");
	game->img_coin = ft_make_xpm_img(game, "coin.xpm");
	game->img_exit = ft_make_xpm_img(game, "exit.xpm");
}

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	*ft_ptr_realloc(void *buf, int before_size, int after_size)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	if (!dst)
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	while (i < before_size)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < after_size)
		dst[i++] = NULL;
	free(buf);
	return ((void *)dst);
}

char	*ft_get_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
