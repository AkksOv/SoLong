#include "../GetNextLine/get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

static void fill_map(char **res, int fd, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        res[i] = get_next_line(fd);
        i++;
    }
    res[i] = NULL;
}

char **generate_map(char *str)
{
    int fd;
    int size;
    char **map;

    size = 0;
    fd = open(str, O_RDONLY);
    while(get_next_line(fd))
        size++;
    close(fd);
    fd = open(str, O_RDONLY);
    map = malloc(sizeof(char *) * (size + 1));
    if(!map)
        return (NULL);
    fill_map(map, fd, size);
    if(check_map_validity(map, size, str_len(map[0]) - 1))
        return (map);
    return (NULL);
}
