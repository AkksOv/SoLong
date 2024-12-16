#include <stdlib.h>

int str_len(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int mapy(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return (i);
}

char *ft_strdup(char *s)
{
    int size;
    char *res;
    int i;

    i = 0;
    size = str_len(s);
    res = malloc(sizeof(char) * size + 1);
    if(!res)
        return (NULL);
    while(i < size)
    {
        res[i] = s[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}