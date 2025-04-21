
#include "../includes/so_long.h"
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    t_game game;

    game = (t_game){0};
    if (ac == 2 && is_valid_ber(av[1]) && is_map_exist(av[1]))
    {
        check_nd_set_all(av[1], &game);

        init_x_system(&game);
        load_textures(&game);
        draw_map(&game);
        mlx_key_hook(game.win, handle_key_press, &game);
        mlx_hook(game.win, 17, 0, close_game, &game);
        mlx_loop(game.mlx);
        free_freeables("All memory has been freed", &game);
    }
    else
    {
        ft_printf("Error\nInvalid arguments or Invalid map\nUsage: ->/so_long <harita->ber>\n");
        return (EXIT_FAILURE);
    }
}
