/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:09:38 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/13 20:17:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ff_recursive(char **map, int x, int y, t_point size)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	ff_recursive(map, x + 1, y, size);
	ff_recursive(map, x - 1, y, size);
	ff_recursive(map, x, y + 1, size);
	ff_recursive(map, x, y - 1, size);
}

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

static void	check_reachability(t_game *game, char **map_copy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'C' && map_copy[i][j] != 'F')
				free_throw("Error: unreachable coin found\n", game, map_copy);
			if (game->map[i][j] == 'E' && map_copy[i][j] != 'F')
				free_throw("Error: unreachable exit found\n", game, map_copy);
			if (game->map[i][j] == '0' && map_copy[i][j] != 'F')
				free_throw("Error: unreachable player found\n", game, map_copy);
		}
	}
}

void	validate_reachability(t_game *game)
{
	char	**map_copy;
	t_point	size;
	int		i;

	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
	{
		free_split(game->map, game->map_height);
		throw_error("MemoryError: couldn't copy map for flood fill\n");
	}
	size.x = game->map_width;
	size.y = game->map_height;
	ff_recursive(map_copy, game->player_cord.x, game->player_cord.y, size);
	check_reachability(game, map_copy);
	i = 0;
	while (i < game->map_height)
		free(map_copy[i++]);
	free(map_copy);
}
