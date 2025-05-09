/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:22:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 05:42:48 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include "libft.h"
#include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"

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
	int		player_x;
	int		player_y;
	int		move_count;
	int 	total_coins;
	int 	collected_coins;
}	t_game;

char	**read_map(char *filename);
void	put_image(t_game *game, void *img, int x, int y);
void	render_map(t_game *game);

// void	init_images(t_game *game);

char	*gnl_strchr(char *s, int c);
void	gnl_strjoin(char **line, char *buff);
void	gnl_new_line(char **line, char *next_lines);
char	*gnl_strdup(char **line);
void	gnl_read(int fd, char **line);
char	*get_next_line(int fd);
int		handle_key(int keycode, t_game *game);

int	validate_map(char **map);
int	is_reachable(char **map);
char	**ft_split_map(char **map);
#endif