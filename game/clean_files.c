/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-23 14:15:54 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-23 14:15:54 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void	clear_images(t_Data *data)
{
	mlx_destroy_image(data->mlx, data->player.imgp[0]);
	mlx_destroy_image(data->mlx, data->player.imgp[1]);
	mlx_destroy_image(data->mlx, data->player.imgp[2]);
	mlx_destroy_image(data->mlx, data->player.imgp[3]);
	mlx_destroy_image(data->mlx, data->imgen[0]);
	mlx_destroy_image(data->mlx, data->imgen[1]);
	mlx_destroy_image(data->mlx, data->imgen[2]);
	mlx_destroy_image(data->mlx, data->imgen[3]);
	mlx_destroy_image(data->mlx, data->imgen[4]);
	mlx_destroy_image(data->mlx, data->imgen[5]);
	mlx_destroy_image(data->mlx, data->imgfloor);
	mlx_destroy_image(data->mlx, data->imgcollect);
	mlx_destroy_image(data->mlx, data->imgwall);
	mlx_destroy_image(data->mlx, data->imgexit[0]);
	mlx_destroy_image(data->mlx, data->imgexit[1]);
	mlx_destroy_image(data->mlx, data->imgexit[2]);
}
