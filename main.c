#include "Utils/utils.h"
#include "GetNextLine/get_next_line.h"
#include <stdio.h>


int main()
{
    char **map;
    map = generate_map("map.txt");
    if(!map)
    {
        printf("map invalide");
        return 0;
    }

    printf("%s", map[0]);
    return 0;
}
