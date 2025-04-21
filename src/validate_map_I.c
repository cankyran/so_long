#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../libs/ft_printf/ft_printf.h"

int is_valid_char(char c)
{
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int validate_chars(char **map)
{
    int y = 0;
    int x;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (!is_valid_char(map[y][x]))
            {
                ft_printf("Error\nInvalid Character: '%c'\n\t    Location: (%d, %d)\n", map[y][x], y, x);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int validate_rectangle(char **map)
{
    int width;
    int y;

    if (!map || !map[0])
        return (0);

    width = ft_strlen(map[0]);
    y = 1;
    while (map[y])
    {
        if ((int)ft_strlen(map[y]) != width)
        {
            ft_printf("Error\nMap is not rectangular.\n%d. line is not equal\n", y + 1);
            return (0);
        }
        y++;
    }
    return (1);
}

int validate_walls(t_game *game)
{
    int x;
    int y;

    x = -1;
    while (++x < game->map_width)
    {
        if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
        {
            ft_printf("Error\nMap top/bottom border is open at column %d\n", x + 1);
            return (0);
        }
    }
    y = -1;
    while (++y < game->map_height)
    {
        if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
        {
            ft_printf("Error\nMap left/right border is open at row %d\n", y + 1);
            return (0);
        }
    }
    return (1);
}

int validate_elements(char **map)
{
    int y = -1;
    int x;
    int p = 0;
    int e = 0;
    int c = 0;

    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            if (map[y][x] == 'P')
                p++;
            else if (map[y][x] == 'E')
                e++;
            else if (map[y][x] == 'C')
                c++;
        }
    }
    if (p != 1 || e != 1 || c < 1)
    {
        ft_printf("Error\nInvalid map element counts:\n P:%d\n E:%d\n C:%d\n", p, e, c);
        return (0);
    }
    return (1);
}
