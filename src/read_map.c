
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void read_map_after_read(int line_count, t_game *game, int i)
{
    if (i < line_count)
    {
        while (--i >= 0)
            free(game->map[i]);
        free(game->map);
        game->map = NULL;
    }
}

int count_lines(const char *filename)
{
    int fd;
    char *line;
    int line_count = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (line_count);
}

void read_map_after_open(int fd, t_game *game)
{
    if (fd == -1)
    {
        free(game->map);
        game->map = NULL;
        return;
    }
}

void read_map_allocate(int line_count, t_game *game)
{
    if (line_count <= 0)
    {
        game->map = NULL;
        return;
    }
    game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
    if (!game->map)
        return;
    game->map[line_count] = NULL;
}

void read_map_file(const char *filename, t_game *game)
{
    int line_count;
    int fd;
    char *line;

    line_count = count_lines(filename);
    int i = 0;
    read_map_allocate(line_count, game);
    fd = open(filename, O_RDONLY);
    read_map_after_open(fd, game);
    while (i < line_count)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        game->map[i] = ft_strdup(line);
        free(line);
        if (!game->map[i])
            break;
        i++;
    }
    close(fd);
    read_map_after_read(line_count, game, i);
    get_next_line(-1);
}
