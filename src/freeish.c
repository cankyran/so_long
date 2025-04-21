
#include "../includes/so_long.h"
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

void free_freeables(char *error, t_game *game)
{
    ft_printf("%s\n", error);
    if (game->img_wall != NULL)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_exit != NULL)
        mlx_destroy_image(game->mlx, game->img_exit);
    if (game->img_coin != NULL)
        mlx_destroy_image(game->mlx, game->img_coin);
    if (game->img_floor != NULL)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player != NULL)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->map != NULL)
        free_map(game->map);
    if (game->win != NULL)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx != NULL)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}

int close_game(void *param)
{
    t_game *game = (t_game *)param;

    free_freeables("GAME CLOSED", game);
    exit(EXIT_SUCCESS);
}
