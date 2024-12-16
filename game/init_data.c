#include "game.h"
#include "../Utils/utils.h"

void    init_data(t_Data *data, char **map)
{
    data->map = map;
    data->mlx = mlx_init();
    data->mlx = mlx_new_window(data->mlx, mapy(map) * 64, (str_len(map[0]) - 1) * 64, "So Long");

}