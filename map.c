/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 05:25:29 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/07 05:25:30 by marshaky         ###   ########.fr       */
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
	{
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
