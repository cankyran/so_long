#include "../includes/so_long.h"
#include "../libs/libft/libft.h"

void get_player_position(t_game *game)
{
    int y = 0;
    int x;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void map_size(t_game *game)
{
    int h;

    game->map_width = ft_strlen(game->map[0]);
    h = 0;
    while (game->map[h])
        h++;
    game->map_height = h;
}

void map_elements(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'C')
                game->coin_count++;
            else if (game->map[y][x] == 'E')
                game->exit_count++;
            else if (game->map[y][x] == 'P')
                game->player_count++;
            x++;
        }
        y++;
    }
}

void set_game_struct(t_game *game)
{
    get_player_position(game);
    map_size(game);
    map_elements(game);
}