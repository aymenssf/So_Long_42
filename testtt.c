#include "so_long.h"
// void     parse_collect(t_map *map)
// {
//         int     i;
//         int     j;

//         i = 0;
//         while(i < map->row)
//         {
//                 j = 0;
//                 while(j < map->col)
//                 {
//                         check_char(map, i, j);
//                         if(map->arr_map[i][j] == 'C')
//                                 map->collect->count += 1;
//                 }
//                 if(map->collect->count == 0)
//                         print_error("Collectibles are less than 1");
//         }
// }
int main()
{
        t_map *map;
        map = malloc(sizeof(t_map));
        map->fd = open("map.ber", O_RDONLY);
        parse_collect(map);
        printf("%d\n",map->collect->count);
        // for(int i; i < map->col; i++)
        //         printf("%s\n", map->arr_map[i]);
        // printf("%d", map->col);
        return(0);
}
