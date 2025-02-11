/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 14:50:19 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 14:50:19 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

char	**copymap(char **map, int size)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	backtrack(char **map, int y, int x)
{
	if (map[y][x] != '0' && map[y][x] != 'P' &&
			map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != 'X')
		return (0);
	if (map[y][x] == 'E' || map[y][x] == '0' ||
			map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'X')
		map[y][x] = 'V';
	backtrack(map, y + 1, x);
	backtrack(map, y, x + 1);
	backtrack(map, y - 1, x);
	backtrack(map, y, x - 1);
	return (1);
}

int	checkmap(char **map, int x)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] != '1' && map[i][j] != 'V' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	freecpy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

int	check_path_validity(char **map, int y, int x, t_Playerpos playerpos)
{
	char	**mapcpy;

	mapcpy = copymap(map, y);
	backtrack(mapcpy, playerpos.y, playerpos.x);
	if (!checkmap(mapcpy, x))
		return (0);
	freecpy(mapcpy);
	return (1);
}
