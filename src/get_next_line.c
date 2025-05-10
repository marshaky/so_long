/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:47:16 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/09 06:49:13 by marshaky         ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE < 1)
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
