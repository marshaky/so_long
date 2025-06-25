/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:44:56 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/25 18:45:46 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0
		|| ext == filename || ext[-1] == '/')
		throw_error("ExtensionError : file name end with .ber\n");
}

void	valid_characters(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			free(line);
			free_throw("CharacterError:invalid character in map\n", game, NULL);
		}
		i++;
	}
}

void	valid_length(char *line, int expected, t_game *game)
{
	if (ft_strlen(line) != expected)
	{
		free_throw("LengthError : inconsistent row width in map\n", game, NULL);
	}
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
			{
				free_split(game->map, game->map_height);
				throw_error("WallError : top/bottom wall must be closed\n");
			}
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[game->map_width - 1] != '1')
		{
			free_split(game->map, game->map_height);
			throw_error("WallError : sides must be closed by walls\n");
		}
	}
}

void	check_component(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		if (game->player_cord.x != -1)
		{
			free_split(game->map, game->map_height);
			throw_error("ComponentError : more than one player\n");
		}
		game->player_cord.x = x;
		game->player_cord.y = y;
		game->map[y][x] = '0';
	}
	else if (c == 'C')
		game->coin_count++;
	else if (c == 'E')
		game->exit_flag++;
}
