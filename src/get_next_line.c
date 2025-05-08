/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:56 by tigpetro          #+#    #+#             */
/*   Updated: 2025/05/08 00:36:25 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*null(char **line)
{
	free(*line);
	return (*line = 0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_lines;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (null(&line));
	if (!line)
	{
		line = (char *)malloc(1);
		if (!line)
			return (0);
		line[0] = '\0';
	}
	else
	{
		next_lines = gnl_strchr(line, '\n');
		if (!next_lines)
			return (null(&line));
		else
			gnl_new_line(&line, next_lines + 1);
	}
	gnl_read(fd, &line);
	return (gnl_strdup(&line));
}
