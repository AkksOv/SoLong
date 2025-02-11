/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 10:44:37 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 10:44:37 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetNextLine/get_next_line.h"
#include "Utils/utils.h"
#include "game/game.h"
#include "minilibx-linux/mlx.h"
#include "printf/ft_printf.h"
#include <stdlib.h>

int	close_with_mouse(void *data)
{
	exit_prog(data, "Goodbye !");
	return (0);
}

int	game_loop(t_Data *data)
{
	static int	count = 0;
	static int	door = 1;

	if (count % 12000 == 0)
		render_enemies(data);
	if (count % 18000 == 0)
		move_enemies(data, count);
	if (count == 100000000)
		count = 0;
	if (data->collect == data->player.collect
		&& door <= 2 && count % 10000 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->imgexit[door], data->exit.pos_x * 64, data->exit.pos_y * 64);
		door++;
	}
	count++;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_Data	*data;
	char	**map;

	if (argc != 2)
	{
		ft_printf("Invalid file\n");
		return (0);
	}
	map = generate_map(argv[1]);
	if (!map)
	{
		ft_printf("Invalid map\n");
		return (0);
	}
	data = NULL;
	data = malloc(sizeof(t_Data));
	if (!data)
		return (0);
	init_data(data, map);
	render_map(data);
	show_counter(data);
	mlx_hook(data->win, 2, 1L << 0, keys, data);
	mlx_hook(data->win, 17, 0, close_with_mouse, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
