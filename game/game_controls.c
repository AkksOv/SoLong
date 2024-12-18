#define ESC     65307
#define W       119
#define A	    97
#define S	    115
#define D	    100

#include "game.h"
#include "../Utils/utils.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int keys(int keycode, t_Data *data)
{
    //printf("Key pressed: %d\n", keycode);
    static int  count = 0;
    if (keycode == ESC)
        exit_prog(data);
    if(keycode == W && data->map[data->player.pos_y - 1][data->player.pos_x] != '1')
        count += movechar(data, -1, 0);  
    if(keycode == S && data->map[data->player.pos_y + 1][data->player.pos_x] != '1')
        count += movechar(data, 1, 0);  
    if(keycode == D && data->map[data->player.pos_y][data->player.pos_x + 1] != '1')
        count += movechar(data, 0, 1);  
    if(keycode == A && data->map[data->player.pos_y][data->player.pos_x - 1] != '1')
        count += movechar(data, 0, -1);
    printf("moves: %d\n", count);
    return 1;
}