/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 12:26:02 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 12:26:02 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define R "Ressources/"
#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>





# include <stdio.h>

void	init_enemies(t_Data *data)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	data->enemies = malloc(sizeof(t_Enemy) * (data->enc));
	while (data->map[i])
	{
		j = 0;
		while (j < (str_len(data->map[0]) - 1))
		{
			if (data->map[i][j] == 'X')
			{
				data->enemies[k].pos_y = i;
				data->enemies[k].pos_x = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_playerpos(t_Data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < (str_len(data->map[0]) - 1))
		{
			if (data->map[i][j] == 'P')
			{
				data->player.pos_y = i;
				data->player.pos_x = j;
			}
			if (data->map[i][j] == 'C')
				data->collect++;
			if (data->map[i][j] == 'X')
				data->enc++;
			j++;
		}
		i++;
	}
}

void	init_images(t_Data *data)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	data->imgfloor = mlx_xpm_file_to_image(data->mlx, R "Floor.xpm", &h, &w);
	data->imgwall = mlx_xpm_file_to_image(data->mlx, R "wall.xpm", &h, &w);
	data->imgcollect = mlx_xpm_file_to_image(data->mlx, R "colle.xpm", &h, &w);
	data->imgexit = mlx_xpm_file_to_image(data->mlx, R "door1.xpm", &h, &w);
	data->player.imgp[0] = mlx_xpm_file_to_image(data->mlx, R "p1.xpm", &h, &w);
	data->player.imgp[1] = mlx_xpm_file_to_image(data->mlx, R "p2.xpm", &h, &w);
	data->player.imgp[2] = mlx_xpm_file_to_image(data->mlx, R "p3.xpm", &h, &w);
	data->player.imgp[3] = mlx_xpm_file_to_image(data->mlx, R "p4.xpm", &h, &w);
	data->imgen[0] = mlx_xpm_file_to_image(data->mlx, R "m1.xpm", &h, &w);
	data->imgen[1] = mlx_xpm_file_to_image(data->mlx, R "m2.xpm", &h, &w);
	data->imgen[2] = mlx_xpm_file_to_image(data->mlx, R "m3.xpm", &h, &w);
	data->imgen[3] = mlx_xpm_file_to_image(data->mlx, R "m4.xpm", &h, &w);
}

void	init_data(t_Data *data, char **map)
{
	data->map = map;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			(str_len(map[0]) - 1) * 64, mapy(map) * 64, "So Long");
	init_images(data);
	init_playerpos(data);
	init_enemies(data);
}

void	exit_prog(t_Data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->map);
	free(data->enemies);
	free(data);
	exit(0);
}
