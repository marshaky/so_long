/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:25:29 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 05:43:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		lines = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

char	**read_map(char *filename)
{
	int		fd;
	int		i = 0;
	int		lines = count_lines(filename);
	char	**map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	return (map);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

int	is_map_rectangular(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_walled(char **map)
{
	int		i;
	int		width;
	int		height;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	int	i = 0;
	int	j;
	int	p = 0;
	int	c = 0;
	int	e = 0;

	if (!is_map_rectangular(map) || !is_map_walled(map))
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (0);
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'C')
				c++;
			else if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	return (p == 1 && c >= 1 && e >= 1);
}

char	**ft_split_map(char **map)
{
	int		i = 0;
	char	**copy;

	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
