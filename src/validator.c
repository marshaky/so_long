/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:44:56 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/10 23:20:54 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
		throw_error("ExtensionError : file must end with .ber");
}

void	valid_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
			throw_error("CharacterError : invalid character in map\n");
		i++;
	}
}

void	valid_length(char *line, int expected)
{
	if (ft_strlen(line) != expected)
		throw_error("LengthError : inconsistent row width in map\n");
}

void	valid_wall(t_game *game, int row)
{
	char	*line;
	int		i;

	line = game->map[row];
	i = 0;
	if (row == 0 || row == game->map_height - 1)
	{
		while (i < game->map_width)
		{
			if (line[i] != '1')
				throw_error("WallError : top/bottom wall must be closed\n");
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[game->map_width - 1] != '1')
			throw_error("WallError : sides must be closed by walls\n");
	}
}

void	check_component(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		if (game->player_cord.x != -1)
			throw_error("ComponentError : more than one player\n");
		game->player_cord.x = x;
		game->player_cord.y = y;
		game->map[y][x] = '0';
	}
	else if (c == 'C')
		game->coin_count++;
	else if (c == 'E')
		game->exit_flag++;
}


void	count_components(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map_height)
	{
		valid_wall(game, y);
		x = 0;
		while (x < game->map_width)
		{
			c = game->map[y][x];
			check_component(game, c, x, y);
			x++;
		}
		y++;
	}
	if (game->player_cord.x == -1)
		throw_error("ComponentError : player not found\n");
	if (game->coin_count < 1)
		throw_error("ComponentError : no coins on map\n");
	if (game->exit_flag < 1)
		throw_error("ComponentError : no exit on map\n");
}
