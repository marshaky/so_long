/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:22:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/07 05:31:22 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectable;
	char	**map;
	int		width;
	int		height;
}	t_game;

char	**read_map(char *filename);
void	put_image(t_game *game, void *img, int x, int y);
void	render_map(t_game *game);

void	init_images(t_game *game);


#endif