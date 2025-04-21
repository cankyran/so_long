#include "../includes/so_long.h"
#include "../libs/ft_printf/ft_printf.h"
#include <X11/keysym.h>

int move_player_extend(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] != '1')
    {
        if (game->map[new_y][new_x] == 'C')
        {
            game->coin_count--;
            game->map[new_y][new_x] = '0';
        }
        if (game->map[new_y][new_x] == 'E' && game->coin_count == 0)
        {
            ft_printf("Congrats! You Won!  Total Moves: %d\n", game->moves);
            return (close_game(game), 0);
        }
        if (game->map[new_y][new_x] != '1')
        {
            if (game->map[game->player_y][game->player_x] != 'E')
                game->map[game->player_y][game->player_x] = '0';
            game->player_x = new_x;
            game->player_y = new_y;
            if (game->map[new_y][new_x] != 'E')
                game->map[new_y][new_x] = 'P';
            game->moves++;
            ft_printf("Moves: %d\n", game->moves);
        }
    }

    return (0);
}

int move_player(int key, t_game *game)
{
    int new_x;
    int new_y;

    new_x = game->player_x;
    new_y = game->player_y;
    if (key == XK_Up || key == XK_w)
        new_y--;
    else if (key == XK_Down || key == XK_s)
        new_y++;
    else if (key == XK_Left || key == XK_a)
        new_x--;
    else if (key == XK_Right || key == XK_d)
        new_x++;
    else
        return (0);
    move_player_extend(game, new_x, new_y);
    draw_map(game);

    return (0);
}

int handle_key_press(int key, t_game *game)
{
    if (key == XK_Escape)
    {
        ft_printf("ESC pressed. Exiting...\n");
        close_game(game);
        return (0);
    }
    move_player(key, game);
    return (0);
}