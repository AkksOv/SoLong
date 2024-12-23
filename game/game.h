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

typedef struct t_exit
{
	int		pos_x;
	int		pos_y;
}			t_Exit;

typedef struct t_player
{
	int		pos_x;
	int		pos_y;
	int		collect;
	void	*imgp[4];
}			t_Player;

typedef struct t_enemy
{
	int		pos_x;
	int		pos_y;
	int		current;
}			t_Enemy;

typedef struct t_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			collect;
	int			enc;
	void		*imgwall;
	void		*imgfloor;
	void		*imgcollect;
	void		*imgexit[3];
	void		*imgen[6];
	t_Player	player;
	t_Exit		exit;
	t_Enemy		*enemies;
}			t_Data;

void	init_data(t_Data *data, char **map);
void	render_map(t_Data *data);
int		movechar(t_Data *data, int y, int x);
void	exit_prog(t_Data *data, char *exitmsg);
int		keys(int keycode, t_Data *data);
void	render_enemies(t_Data *data);
void	move_enemies(t_Data *data, int seed);
void	draw_rectangle(t_Data *data);
void	show_counter(t_Data *data);
void	clear_images(t_Data *data);

#endif