#include "utils.h"

int check_size(char **map, int size)
{
    int i;
    int k;

    i = 0;
    while(map[i])
    {
        k = 0;
        while(map[i][k] && map[i][k] != '\n')
            k++;
        if(k != size)
            return 0;
        i++;
    }
    return (1);
}

int check_wall(char **map,int y, int x)
{
    int i;

    i = -1;
    while(++i, i < x)
        if(map[0][i] != '1')
            return (0);
    i = -1;
    while(++i, i < x)
        if(map[y-1][i] != '1')
            return (0);
    i = -1;
    while(++i, i < y)
        if(map[i][x-1] != '1')
            return (0);
    i = -1;
    while(++i, i < y)
        if(map[i][0] != '1')
            return (0);
    return (1);
}

int check_map_validity(char **map, int y, int x)
{
    if(!check_size(map, x))
        return (0);
    if(!check_wall(**map, y, x))
        return (0);
    return (1);
}       

