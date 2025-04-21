#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

void find_player_position(char **map, t_game *game, t_point *player)
{
    int y;
    int x;

    player->x = -1;
    player->y = -1;
    y = -1;
    while (map[++y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
            }
            x++;
        }
    }
    if (player->x == -1 || player->y == -1)
    {
        free_freeables("Error\nPlayer not found in the map!\n", game);
        exit(EXIT_FAILURE);
    }
}

char **copy_map(t_game *game)
{
    char **copy;
    int i;

    copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < game->map_height)
    {
        copy[i] = ft_strdup(game->map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void flood_fill(char **map, int x, int y, t_counter *count)
{
    if (!map[y] || !map[y][x])
        return;

    if (map[y][x] == '1' || map[y][x] == 'X')
        return;

    if (map[y][x] == 'C')
        count->reached_coin++;
    else if (map[y][x] == 'E')
        count->reached_exit++;

    map[y][x] = 'X';

    flood_fill(map, x + 1, y, count);
    flood_fill(map, x - 1, y, count);
    flood_fill(map, x, y + 1, count);
    flood_fill(map, x, y - 1, count);
}

int validate_path(t_game *game)
{
    t_point player;
    t_counter count = {0, 0};
    char **copy;

    copy = copy_map(game);
    if (!copy)
    {
        ft_printf("Error\nMap copy failed!...in validate_path func\n");
        return (0);
    }

    find_player_position(copy, game, &player);
    flood_fill(copy, player.x, player.y, &count);
    free_map(copy);

    if (count.reached_coin != game->coin_count || count.reached_exit != game->exit_count)
    {
        ft_printf("Error\nNot all coins or the exit are reachable from the player's starting position!\n");
        return (0);
    }
    return (1);
}
