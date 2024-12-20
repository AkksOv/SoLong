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
	init_data(data, map);
	render_map(data);
	render_enemies(data);
	mlx_hook(data->win, 2, 1L << 0, keys, data);
	mlx_loop(data->mlx);
}
