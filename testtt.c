#include "so_long.h"
void    count_line(t_map *map)
{
        char *buff;

        buff = get_next_line(map->fd);
        printf("%s", buff);
        if(buff == 0)
                printf("Error in map");
        map->col = strlen(buff);
        while(buff != NULL)
        {
                free(buff);
                map->row++;
                buff = get_next_line(map->fd);
                if(buff == NULL)
                        free(buff);
        }
}
int main()
{
        t_map *map;
        map = malloc(sizeof(t_map));
        map->fd = open("map.ber", O_RDONLY);
        count_line(map);
        printf("%d\n", map->row);
        printf("%d", map->col);
        return(0);
}