/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:07:28 by jepenoy           #+#    #+#             */
/*   Updated: 2024/11/25 11:42:41 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*endloop(char *res, size_t count)
{
	res[count] = '\0';
	res = ft_realloc(res, count, ft_strlen(res));
	if (!res)
		return (NULL);
	return (res);
}

int	reload_buffer(int fd, t_BufferInfo *bufi)
{
	if (bufi->index >= bufi->size)
	{
		bufi->size = read(fd, bufi->buf, BUFFER_SIZE);
		if (bufi->size == -1)
			return (-1);
		bufi->index = 0;
		if (bufi->size == 0)
			return (0);
	}
	return (1);
}

size_t	line_fl(char **res, size_t count, size_t *res_size, t_BufferInfo *bufi)
{
	while (bufi->index < bufi->size && bufi->buf[bufi->index] != '\n')
	{
		if (count >= *res_size - 1)
		{
			*res_size += BUFFER_SIZE + 1;
			*res = ft_realloc(*res, count, *res_size + 1);
			if (!*res)
				return (0);
		}
		(*res)[count++] = bufi->buf[bufi->index++];
	}
	return (count);
}

char	*strmaker(size_t count, size_t res_size, char *res, int fd)
{
	static t_BufferInfo	bufi;
	int					reload_status;

	while (1)
	{
		reload_status = reload_buffer(fd, &bufi);
		if (reload_status == -1)
			return (freenull(res));
		if (reload_status == 0)
		{
			if (count == 0)
				return (freenull(res));
			break ;
		}
		count = line_fl(&res, count, &res_size, &bufi);
		if (!res)
			return (NULL);
		if (bufi.index < bufi.size && \
			bufi.buf[bufi.index] == '\n')
		{
			res[count++] = bufi.buf[bufi.index++];
			break ;
		}
	}
	return (endloop(res, count));
}

char	*get_next_line(int fd)
{
	char	*res;
	size_t	count;
	size_t	res_size;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	count = 0;
	res_size = BUFFER_SIZE;
	return (strmaker(count, res_size, res, fd));
}
