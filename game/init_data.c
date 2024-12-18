#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void    init_playerpos(t_Data *data)
{
    int i;
    int j;

    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(j < (str_len(data->map[0]) - 1))
        {
            if(data->map[i][j] == 'P')
            {
                data->player.pos_y = i;
                data->player.pos_x = j;
            }
            if(data->map[i][j] == 'C')
                data->collect++;
            j++;
        }
        i++;
    }
}

void    init_images(t_Data *data)
{   
    int height = 64;
    int width = 64;
    data->imgfloor = mlx_xpm_file_to_image(data->mlx, "Ressources/Floor.xpm", &height, &width);
    data->imgwall = mlx_xpm_file_to_image(data->mlx, "Ressources/wall.xpm", &height, &width);
    data->imgcollect = mlx_xpm_file_to_image(data->mlx, "Ressources/collect.xpm", &height, &width);
    data->player.imgplayer[0] = mlx_xpm_file_to_image(data->mlx, "Ressources/player1.xpm", &height, &width);
    data->player.imgplayer[1] = mlx_xpm_file_to_image(data->mlx, "Ressources/player2.xpm", &height, &width);
    data->player.imgplayer[2] = mlx_xpm_file_to_image(data->mlx, "Ressources/player3.xpm", &height, &width);
    data->player.imgplayer[3] = mlx_xpm_file_to_image(data->mlx, "Ressources/player4.xpm", &height, &width);
} 

void    init_data(t_Data *data, char **map)
{
    data->map = map;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, (str_len(map[0]) - 1) * 64, mapy(map) * 64 , "So Long");
    init_images(data);
    init_playerpos(data);
}



void    exit_prog(t_Data *data)
{   
    mlx_destroy_window(data->mlx, data->win);
    free(data);
    exit(0);
}
