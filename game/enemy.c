/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-21 10:18:29 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-21 10:18:29 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	change_enemy_pos(t_Data *data, int en, char axis, int value)
{
	int	y;
	int	x;

	y = data->enemies[en].pos_y;
	x = data->enemies[en].pos_x;
	data->map[y][x] = '0';
	if (axis == 'X')
		data->enemies[en].pos_x += value;
	if (axis == 'Y')
		data->enemies[en].pos_y += value;
	mlx_put_image_to_window(data->mlx,
		data->win, data->imgfloor, x * 64, y * 64);
	y = data->enemies[en].pos_y;
	x = data->enemies[en].pos_x;
	data->map[y][x] = 'X';
}

void	check_dead(t_Data *data, int randnum, int i)
{
	int	ex;
	int	ey;

	ex = data->enemies[i].pos_x;
	ey = data->enemies[i].pos_y;
	if (randnum == 0 && data->map[ey + 1][ex] == 'P')
		exit_prog(data, "You are dead :(");
	if (randnum == 1 && data->map[ey - 1][ex] == 'P')
		exit_prog(data, "You are dead :(");
	if (randnum == 2 && data->map[ey][ex + 1] == 'P')
		exit_prog(data, "You are dead :(");
	if (randnum == 3 && data->map[ey][ex - 1] == 'P')
		exit_prog(data, "You are dead :(");
}

void	move_enemies(t_Data *data, int seed)
{
	int	i;
	int	randnum;
	int	ex;
	int	ey;

	srand(seed);
	i = 0;
	while (i < data->enc)
	{
		ex = data->enemies[i].pos_x;
		ey = data->enemies[i].pos_y;
		randnum = rand() % 4;
		check_dead(data, randnum, i);
		if (randnum == 0 && data->map[ey + 1][ex] == '0')
			change_enemy_pos(data, i, 'Y', 1);
		if (randnum == 1 && data->map[ey - 1][ex] == '0')
			change_enemy_pos(data, i, 'Y', -1);
		if (randnum == 2 && data->map[ey][ex + 1] == '0')
			change_enemy_pos(data, i, 'X', 1);
		if (randnum == 3 && data->map[ey][ex - 1] == '0')
			change_enemy_pos(data, i, 'X', -1);
		i++;
	}
	render_enemies(data);
}
