NAME = so_long

SRC = 		  src/so_long.c \
	 		 src/freeish.c   \
			src/read_map.c    \
	  	   src/movement.c      \
	  	  src/run_x_system.c    \
	  	 src/validate_map_I.c    \
	    src/validate_map_II.c     \
	   src/map_check_nd_read.c     \
  	  src/game_struct_fillers.c     \
	 src/game_struct_image_loaders.c \

OBJ = $(SRC:.c=.o)

# Derleyici ve flag'ler
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = -Llibs/minilibx-linux -lmlx -lX11 -lXext -lm -lz

# Harici kütüphaneler
LIBFT = libs/libft/libft.a
FT_PRINTF = libs/ft_printf/libftprintf.a
GET_NEXT_LINE = libs/get_next_line/libgnl.a

# Derleme kuralları
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libs/libft

$(FT_PRINTF):
	$(MAKE) -C libs/ft_printf

$(GET_NEXT_LINE):
	$(MAKE) -C libs/get_next_line

clean:
	rm -f $(OBJ)
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/ft_printf clean
	$(MAKE) -C libs/get_next_line clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libs/libft fclean
	$(MAKE) -C libs/ft_printf fclean
	$(MAKE) -C libs/get_next_line fclean

re: fclean all

.PHONY: all clean fclean re