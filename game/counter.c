/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-23 10:56:55 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-23 10:56:55 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "../printf/ft_printf.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void	draw_rectangle(t_Data *data)
{
	int	i;
	int	j;

	i = 15;
	j = 5;
	while (i < 58)
	{
		while (j < 33)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 8);
			j++;
		}
		i++;
		j = 10;
	}
}

static int	count_signs(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*res;
	long int	nb;

	nb = (long int) n;
	size = count_signs(nb);
	res = malloc(sizeof(char) * (size +1));
	if (res == NULL)
		return (0);
	res[size] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (--size, nb > 0)
	{
		res[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}

void	show_counter(t_Data *data)
{
	static int	i = 0;

	draw_rectangle(data);
	mlx_string_put(data->mlx, data->win, 40, 25, 0xFFFFFF, ft_itoa(i));
	i++;
}
