

#include "../includes/so_long.h"
#include "../libs/ft_printf/ft_printf.h"
#include "../libs/get_next_line/get_next_line.h"
#include "../libs/libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int is_valid_ber(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 5)
        return (0);

    if (filename[len - 4] == '.' && filename[len - 3] == 'b' && filename[len - 2] == 'e' && filename[len - 1] == 'r')
        return (1);
    return (0);
}

int is_map_exist(char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\nCould not open file->\n");
        return (0);
    }
    line = get_next_line(fd);
    if (!line || line[0] == '\0' || line[0] < 33 || line[0] > 126)
    {
        free(line);
        close(fd);
        ft_printf("Error\nEmpty map\n");
        return (0);
    }
    free(line);
    line = NULL;
    close(fd);
    return (1);
}

int is_map_playable(t_game *game)
{
    if (!validate_chars(game->map) || !validate_rectangle(game->map) ||
        !validate_walls(game) || !validate_elements(game->map) ||
        !validate_path(game))
    {
        return (0);
    }
    return (1);
}
void check_nd_set_all(char *filename, t_game *game)
{
    read_map_file(filename, game);
    if (!game->map)
    {
        free_freeables("Error\nMap could not be read->\n", game);
        exit(EXIT_FAILURE);
    }
    set_game_struct(game);

    if (!is_map_playable(game))
    {
        free_freeables("Map is not playable\n", game);
        exit(EXIT_FAILURE);
    }
}
