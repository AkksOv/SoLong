/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 15:00:31 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 15:00:31 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"

int	movechar(t_Data *data, int y, int x)
{
	static int	i = 0;

	if (data->map[data->player.pos_y + y][data->player.pos_x + x] == 'E' &&
			data->collect == data->player.collect)
		exit_prog(data);
	else if (data->map[data->player.pos_y + y][data->player.pos_x + x] == 'E')
		return (0);
	i += x;
	if (i > 3)
		i = 0;
	if (i < 0)
		i = 3;
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->imgfloor,
		data->player.pos_x * 64, data->player.pos_y * 64);
	data->player.pos_y += y;
	data->player.pos_x += x;
	if (data->map[data->player.pos_y][data->player.pos_x] == 'C')
		data->player.collect++;
	data->map[data->player.pos_y][data->player.pos_x] = 'P';
	mlx_put_image_to_window(data->mlx, data->win, data->player.imgp[i],
		data->player.pos_x * 64, data->player.pos_y * 64);
	return (1);
}

static void	select_char(t_Data *data, int i, int j)
{
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgfloor, j * 64, i * 64);
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgwall, j * 64, i * 64);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player.imgp[0], j * 64, i * 64);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgcollect, j * 64, i * 64);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgexit, j * 64, i * 64);
}

void render_enemies(t_Data *data)
{
    int i;
    static int k = 0;

    i = 0;
    if (k == 3)
	{
		k = 0;
	}
	while (i < data->enc)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgen[k],
			data->enemies[i].pos_x * 64, data->enemies[i].pos_y * 64);
		i++;
	}
	k++;
}


void	render_map(t_Data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i, data->map[i])
	{
		j = -1;
		while (++j < str_len(data->map[0]) - 1)
			select_char(data, i, j);
	}
}
