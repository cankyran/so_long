#include "../includes/so_long.h"
#include "../libs/ft_printf/ft_printf.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdlib.h>

void check_texture_size(int w, int h, t_game *game)
{
    if (w != TILE_SIZE || h != TILE_SIZE)
    {
        ft_printf("Error\nTexture size must be %dx%d. Current: %dx%d\n",
                  TILE_SIZE, TILE_SIZE, w, h);
        free_freeables("All memory has been freed", game);
        exit(EXIT_FAILURE);
    }
}
void check_load(char *image_name, void *img, t_game *game)
{
    if (img == NULL)
    {
        ft_printf("Error\n%s image could not be loaded\n", image_name);
        free_freeables("All memory has been freed", game);
        exit(EXIT_FAILURE);
    }
}

void load_textures(t_game *game)
{
    int w;
    int h;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
    check_load("Wall", game->img_wall, game);
    check_texture_size(w, h, game);

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
    check_load("Floor", game->img_floor, game);
    check_texture_size(w, h, game);

    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
    check_load("Player", game->img_player, game);
    check_texture_size(w, h, game);

    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
    check_load("Exit", game->img_exit, game);
    check_texture_size(w, h, game);

    game->img_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &w, &h);
    check_load("Coin", game->img_coin, game);
    check_texture_size(w, h, game);
}

void draw_map(t_game *game)
{
    int x;
    int y;

    y = -1;
    while (++y < game->map_height)
    {
        x = -1;
        while (++x < game->map_width)
        {
            mlx_put_image_to_window(game->mlx, game->win,
                                    game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win,
                                        game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win,
                                        game->img_player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win,
                                        game->img_coin, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win,
                                        game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}
