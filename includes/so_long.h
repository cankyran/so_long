#ifndef SO_LONG_H
#define SO_LONG_H

#define TILE_SIZE 64

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct s_counter
{
    int reached_coin;
    int reached_exit;
} t_counter;

typedef struct s_game
{
    char **map;
    int map_width;
    int map_height;

    int player_x;
    int player_y;

    int player_count;
    int exit_count;
    int coin_count;

    int moves;

    void *mlx;
    void *win;
    void *img_wall;
    void *img_floor;
    void *img_player;
    void *img_coin;
    void *img_exit;
} t_game;

void check_nd_set_all(char *filename, t_game *game);
void read_map_file(const char *filename, t_game *game);
int is_valid_ber(char *filename);
int is_map_exist(char *filename);
int is_map_playable(t_game *game);
int validate_chars(char **map);
int validate_rectangle(char **map);
int validate_walls(t_game *game);
int validate_elements(char **map);
int validate_path(t_game *game);

void map_size(t_game *game);
void map_elements(t_game *game);
void get_player_position(t_game *game);
void set_game_struct(t_game *game);

void init_x_system(t_game *game);
void load_textures(t_game *game);
void draw_map(t_game *game);

int handle_key_press(int key, t_game *game);
int move_player(int key, t_game *game);
int move_player_extend(t_game *game, int new_x, int new_y);

void free_freeables(char *error, t_game *game);
void free_map(char **map);
int close_game(void *param);

#endif