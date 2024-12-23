/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 14:42:35 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 14:42:35 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ESC     65307
#define W       119
#define A	    97
#define S	    115
#define D	    100

#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	keys(int keycode, t_Data *data)
{
	static int	count = 0;
	int			x;
	int			y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (keycode == ESC)
		exit_prog(data, "Goodbye");
	if (keycode == W && data->map[y - 1][x] != '1')
		count += movechar(data, -1, 0);
	if (keycode == S && data->map[y + 1][x] != '1')
		count += movechar(data, 1, 0);
	if (keycode == D && data->map[y][x + 1] != '1')
		count += movechar(data, 0, 1);
	if (keycode == A && data->map[y][x - 1] != '1')
		count += movechar(data, 0, -1);
	show_counter(data);
	return (1);
}
