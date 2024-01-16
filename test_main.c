#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
// ... (include the header with the t_map definition and validate_wall declaration)

void create_and_validate_map(const char *file_path)
{
    t_map   map;
    int     i = 0;

    map.row = 0; // Fill in the correct number of rows in your map
    map.col = 0; // Fill in the correct number of columns in your map
    map.fd = open(file_path, O_RDONLY);
    if (map.fd < 0)
    {
        print_error("Error opening the map file.\n");
    }

    // Count the number of lines in the map file to set 'map.row'
    // Implementation of 'count_rows_in_map' needed here

    // Allocate memory for the map data
    map.arr_map = (char **)malloc(sizeof(char *) * (map.row + 1)); // Including space for a NULL terminator
    if (!map.arr_map)
    {
        close(map.fd);
        print_error("Failed to allocate memory for map array.\n");
    }

    while (i < map.row)
    {
        map.arr_map[i] = get_next_line(map.fd);
        if (!map.arr_map[i])
        {
            close(map.fd);
            print_error("Failed to read the map from the file.\n");
        }
        i++;
    }
    map.arr_map[i] = NULL; // NULL terminate the array of strings

    close(map.fd);

    // Run 'validate_wall' and handle the result
    if (validate_wall(&map) == 1)
    {
        printf("success");
        // Handle error if 'validate_wall' returns non-zero
        // Since 'print_error' exits, no need for specific error handling here
    }
    else
    {
        printf("error\n");
    }

    // Freeing memory for each row and then for the array itself
    for (i = 0; i < map.row; ++i)
    {
        free(map.arr_map[i]);
    }
    free(map.arr_map);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
        return EXIT_FAILURE;
    }

    create_and_validate_map(argv[1]);

    return EXIT_SUCCESS;
}