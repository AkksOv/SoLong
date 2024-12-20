/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepenoy <jepenoy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 15:33:20 by jepenoy           #+#    #+#             */
/*   Updated: 2024-12-19 15:33:20 by jepenoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct t_player
{
	int		pos_x;
	int		pos_y;
	int		collect;
	void	*imgp[4];
}			t_Player;

typedef struct t_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			collect;
	void		*imgwall;
	void		*imgfloor;
	void		*imgcollect;
	void		*imgexit;
	t_Player	player;
}			t_Data;

void	init_data(t_Data *data, char **map);
void	render_map(t_Data *data);
int		movechar(t_Data *data, int y, int x);
void	exit_prog(t_Data *data);
int		keys(int keycode, t_Data *data);

#endif