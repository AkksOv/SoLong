/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:47:44 by jepenoy           #+#    #+#             */
/*   Updated: 2024/11/20 12:05:15 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*ft_realloc(void *p, size_t old_size, size_t new_size)
{
	char	*res;

	if (new_size <= old_size)
		return (p);
	res = malloc(new_size);
	if (!res)
	{
		free(p);
		return (NULL);
	}
	if (p)
	{
		ft_memcpy(res, p, old_size);
		free(p);
	}
	return (res);
}

char	*freenull(char *res)
{
	free(res);
	return (NULL);
}
