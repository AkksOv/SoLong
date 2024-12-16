#include "Utils/utils.h"
#include "GetNextLine/get_next_line.h"
#include "game/game.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>


int main()
{
    char **map;
    t_Data data;
    map = generate_map("map.txt");
    if(!map)
    {
        printf("map invalide");
        return 0;
    }

    init_data(&data, map);
    return 0;
}
