/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:17:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/21 03:16:45 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_ptr_realloc(void *buf, int before_size, int after_size)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
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
	while (i < after_size)
		dst[i++] = NULL;
	free(buf);
	return ((void *)dst);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
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
