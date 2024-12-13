/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:11:35 by jepenoy           #+#    #+#             */
/*   Updated: 2024/11/16 13:25:21 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct t_bufferinfo
{
	char	buf[BUFFER_SIZE];
	int		index;
	int		size;
}			t_BufferInfo;

int			ft_strlen(char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*freenull(char *res);
void		*ft_realloc(void *p, size_t old_size, size_t new_size);
char		*endloop(char *res, size_t count);
int			reload_buffer(int fd, t_BufferInfo *bufi);
size_t		line_fl(char **res, size_t count, size_t *res_size,
				t_BufferInfo *bufi);
char		*strmaker(size_t count, size_t res_size, char *res, int fd);
char		*get_next_line(int fd);

#endif