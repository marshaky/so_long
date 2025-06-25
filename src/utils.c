/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:17:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/06/25 18:38:05 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_ptr_realloc(void *buf, int before_size, int after_size)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * (after_size + 1));
	if (!dst)
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	while (i < before_size)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < after_size + 1)
		dst[i++] = NULL;
	free(buf);
	return ((void *)dst);
}

void	free_split(char **str, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(str[i]);
		i++;
	}
	free (str);
}

char	*ft_get_line(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

void	free_throw(char *str, t_game *game, char **map_copy)
{
	if (map_copy)
		free_split(map_copy, game->map_height);
	free_split(game->map, game->map_height);
	get_next_line(-1);
	throw_error(str);
}
