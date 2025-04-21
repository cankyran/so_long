
#include "../includes/so_long.h"
#include "../libs/minilibx-linux/mlx.h"

void init_x_system(t_game *game)
{
    int tile_size;
    int screen_width;
    int screen_height;
    int window_width;
    int window_height;

    game->mlx = mlx_init();
    if (!game->mlx)
        free_freeables("Error\nMLX initialization failed!\n", game);
    mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
    tile_size = TILE_SIZE;
    window_width = game->map_width * tile_size;
    window_height = game->map_height * tile_size;
    if (window_width > screen_width)
        window_width = screen_width;
    if (window_height > screen_height)
        window_height = screen_height;
    if (window_width < tile_size)
        window_width = tile_size;
    if (window_height < tile_size)
        window_height = tile_size;
    game->win = mlx_new_window(game->mlx, window_width, window_height, "Hitchhiker's Guide to the Galaxy");
    if (!game->win)
        free_freeables("Error\nWindow creation failed!\n", game);
}
