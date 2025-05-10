/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:17:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/10 04:40:22 by marshaky         ###   ########.fr       */
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
		printf("fileName: %s\n", xpm_file);
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
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}

char	*ft_get_line(int fd)
{
	char	*line;
	char	eol;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return (line);
}

void	throw_error(char *message)
{
	ft_putstr_fd("\033[31mError\n\033[0m", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}