#ifndef UTILS_H
# define UTILS_H

typedef struct t_playerpos
{
	int		y;
	int		x;
}			t_Playerpos;

int     str_len(char *s);
char    *ft_strdup(char *s);
int check_path_validity(char **map, int y, int x, t_Playerpos playerpos);
int check_map_validity(char **map, int y, int x);
char **generate_map(char *str);
int mapy(char **map);

#endif