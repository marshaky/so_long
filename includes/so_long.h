/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:22:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/25 19:06:13 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"

# define KEY_EXIT 17
# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_A 0
#  define KEY_ESC 53
#  define KEY_Q 12
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
# else
#  define KEY_EXIT 17
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_A 97
#  define KEY_ESC 65307
#  define KEY_Q 113
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
# endif
# define ASSET_PATH "./textures/"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	char	**visited;
	int		exit_flag;
	int		coin_count;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		moves;
	int		move_status;
	int		endgame;
	t_point	map_cord;
	t_point	exit;
	t_point	player_cord;

}	t_game;

void	draw_tiles(t_game *game);
void	draw_exit(t_game *game);
void	draw_player(t_game *game);
void	draw_init(t_game *game);
void	draw_animate_collect(t_game *game);
void	find_player_position(t_game *game);
void	init_window(t_game *game);
void	init_imgs(t_game *game);
void	start_game(t_game *game);
int		close_game(t_game *game);
void	handle_collect(t_game *game);
void	handle_exit(t_game *game);
void	handle_location(t_game *game, int dx, int dy);
void	move_key_hook(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
int		loop_hook(t_game *game);
void	init_map(t_game *game, char *line);
void	read_map(t_game *game, char *file);
void	*ft_make_xpm_img(t_game *game, char *xpm_file);
void	ft_put_img(t_game *game, void *img, int x, int y);
void	destroy_imgs(t_game *game);
void	*ft_ptr_realloc(void *buf, int before_size, int after_size);
char	*ft_get_line(int fd);
void	throw_error(char *message);
void	valid_extension(char *filename);
void	valid_characters(char *line, t_game *game);
void	valid_length(char *line, int expected, t_game *game);
void	valid_wall(t_game *game, int row);
void	check_component(t_game *game, char c, int x, int y);
void	count_components(t_game *game);
int		count_coins(t_game *game);
void	validate_reachability(t_game *game);
char	*gnl_strchr(char *s, int c);
void	gnl_strjoin(char **line, char *buff);
void	gnl_new_line(char **line, char *next_lines);
char	*gnl_strdup(char **line);
void	gnl_read(int fd, char **line);
char	*get_next_line(int fd);
void	show_door(t_game *game);
void	save_exit(t_game *game);
void	free_split(char **str, int height);
void	count_comp_free(t_game *game);
void	free_throw(char *str, t_game *game, char **map_copy);
void	ft_clean(t_game *game);

#endif
