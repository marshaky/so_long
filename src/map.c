/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:25:29 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/10 23:20:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char *line)
{
	game->map = (char **)malloc(sizeof(char *) * 1);
	if (!game->map)
		throw_error("MemoryError : failed to allocate map\n");

	game->map[0] = line;
	game->map_width = ft_strlen(line);
	game->map_height = 1;
	game->coin_count = 0;
	game->exit_flag = 0;
	game->player_cord.x = -1;
	game->player_cord.y = -1;
}

static void	add_map_line(t_game *game, char *line, int row)
{
	char	**tmp;

	valid_characters(line);
	valid_length(line, game->map_width);
	game->map_height++;
	tmp = (char **)ft_ptr_realloc(game->map, row, row + 1);
	if (!tmp)
		throw_error("MemoryError : realloc failed\n");
	game->map = tmp;
	game->map[row] = line;
}

static void	open_and_read_map(t_game *game, int fd)
{
	char	*line;
	int		row;

	row = 1;
	line = ft_get_line(fd);
	if (!line)
		throw_error("FileError : map file is empty\n");
	init_map(game, line);
	while ((line = ft_get_line(fd)))
		add_map_line(game, line, row++);
	close(fd);
}

void	read_map(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		throw_error("FileError : failed to open map\n");
	open_and_read_map(game, fd);
}
