#define ESC     65307
#define W       119
#define A	    97
#define S	    115
#define D	    100

#include "Utils/utils.h"
#include "GetNextLine/get_next_line.h"
#include "game/game.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>



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

int main()
{
    t_Data  *data;
    char **map;

    map = generate_map("map.txt");
    if(!map)
    {
        printf("invalid map");
        return 0;
    }
    data = NULL;
    data = malloc(sizeof(t_Data));
    printf("%d\n", str_len(map[0]));
    init_data(data, map);
    render_map(data);
    mlx_hook(data->win, 2, 1L << 0, keys, data);
    mlx_loop(data->mlx);
}
