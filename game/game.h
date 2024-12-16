#ifndef GAME_H
# define GAME_H

typedef struct t_data
{
    void    *mlx;
    void    *win;
	char	**map;
}			t_Data;

void    init_data(t_Data *data, char **map);

#endif