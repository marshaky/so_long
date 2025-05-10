/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:09:38 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/11 03:15:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, height, width);
	flood_fill(map, x - 1, y, height, width);
	flood_fill(map, x, y + 1, height, width);
	flood_fill(map, x, y - 1, height, width);
}

static char	**copy_map(t_game *game)
{
	int		y;
	char	**copy;

	copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
		throw_error("MemoryError: can't allocate map copy");

	y = 0;
	while (y < game->map_height)
	{
		copy[y] = ft_strdup(game->map[y]);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

static void	free_map_copy(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	validate_path(t_game *game)
{
	char	**map_copy = copy_map(game);
	int		x = game->player_cord.x;
	int		y = game->player_cord.y;
	int		i, j;

	flood_fill(map_copy, x, y, game->map_height, game->map_width);

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && map_copy[i][j] != 'F')
			{
				free_map_copy(map_copy);
				throw_error("PathError: unreachable coin or exit\n");
			}
			j++;
		}
		i++;
	}
	free_map_copy(map_copy);
}
