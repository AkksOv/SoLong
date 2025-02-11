/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 12:00:36 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 12:00:36 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

int	check_size(char **map, int size)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k] && map[i][k] != '\n')
			k++;
		if (k != size)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **map, int y, int x)
{
	int	i;

	i = -1;
	while (++i, i < x)
		if (map[0][i] != '1')
			return (0);
	i = -1;
	while (++i, i < x)
		if (map[y - 1][i] != '1')
			return (0);
	i = -1;
	while (++i, i < y)
		if (map[i][x - 1] != '1')
			return (0);
	i = -1;
	while (++i, i < y)
		if (map[i][0] != '1')
			return (0);
	return (1);
}

int	check_player_exit(char **map, int y, int x, t_Playerpos *playerpos)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if (map[i][j] == 'P')
			{
				playerpos->y = i;
				playerpos->x = j;
				player++;
			}
			if (map[i][j] == 'E')
				exit++;
		}
	}
	return (player == 1 && exit == 1);
}

int	check_map_validity(char **map, int y, int x)
{
	t_Playerpos	playerpos;

	if (!check_size(map, x))
		return (0);
	if (!check_wall(map, y, x))
		return (0);
	if (!check_player_exit(map, y, x, &playerpos))
		return (0);
	if (!check_path_validity(map, y, x, playerpos))
		return (0);
	return (1);
}
