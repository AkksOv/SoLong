#include "Utils/utils.h"
#include "GetNextLine/get_next_line.h"
#include "game/game.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>


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
