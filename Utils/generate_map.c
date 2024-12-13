#include "../GetNextLine/get_next_line.h"
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
    fill_map(map, fd, size);

    for(int j = 0; map[j]; j++)
        printf("%s", map[j]);
    return map;
}
