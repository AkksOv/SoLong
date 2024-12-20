/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 15:37:05 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 15:37:05 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GetNextLine/get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include "../printf/ft_printf.h"
#include <unistd.h> 

static void	fill_map(char **res, int fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		res[i] = get_next_line(fd);
		i++;
	}
	res[i] = (NULL);
}

char	**generate_map(char *str)
{
	int		fd;
	int		size;
	char	**map;

	size = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd))
		size++;
	close(fd);
	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fill_map(map, fd, size);
	if (check_map_validity(map, size, str_len(map[0]) - 1))
		return (map);
	return (NULL);
}
