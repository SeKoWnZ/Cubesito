NAME = cub3D
MLX = ./lib/MLX42
LIBFT = ./lib/Libft

FLAGS = -g -Wall -Wextra -Werror -I./include/ #-fsanitize=address
LFLAGS = -L$(LIBFT) -lft -L$(MLX)/build -lmlx42 -Iinclude -lglfw -ldl -lm -no-pie

FILES = cube3D.c init_cub.c parse_map.c valid_map.c parse_color.c parse_check.c error.c \
square_map.c mlx_run.c mlx_keys.c cube_it.c raycast.c ray_cal_x.c ray_cal_y.c \
draw_ray.c player.c animation.c

SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(FILES:%=$(SRC_DIR)/%)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: libft mlx42 $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

mlx42:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

$(NAME_BONUS): $(B_OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_B)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C $(LIBFT) clean
	rm -rf $(MLX)/build
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	rm -rf $(MLX)/build
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
