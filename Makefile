NAME = cub3D
NAME_BONUS = cub3D_bonus

MLX = ./lib/MLX42
LIBFT = ./lib/Libft

FLAGS = -g -Wall -Wextra -Werror -I./include/ #-fsanitize=address
LFLAGS = -L$(LIBFT) -lft -L$(MLX)/build -lmlx42 -Iinclude -lglfw -ldl -lm -no-pie

FILES = cube3D.c init_cub.c parse_map.c valid_map.c parse_color.c parse_check.c error.c \
square_map.c mlx_run.c mlx_keys.c cube_it.c raycast.c ray_cal_x.c ray_cal_y.c \
draw_ray.c player.c

B_FILES = cube3D_bonus.c init_cub_bonus.c parse_map_bonus.c valid_map_bonus.c \
parse_color_bonus.c parse_check_bonus.c error_bonus.c square_map_bonus.c \
mlx_run_bonus.c mlx_keys_bonus.c cube_it_bonus.c raycast_bonus.c ray_cal_x_bonus.c \
ray_cal_y_bonus.c draw_ray_bonus.c player_bonus.c animation_bonus.c

SRC_DIR = src
SRC_B =src_bonus

OBJ_DIR = obj
OBJ_B = obj_bonus

SOURCES = $(FILES:%=$(SRC_DIR)/%)
B_SOURCES = $(B_FILES:%=$(SRC_B)/%)

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
B_OBJECTS = $(patsubst $(SRC_B)/%.c, $(OBJ_B)/%.o, $(B_SOURCES))

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

bonus: libft mlx42 $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_B)/%.o: $(SRC_B)/%.c
	@mkdir -p $(OBJ_B)
	gcc $(FLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C $(LIBFT) clean
	rm -rf $(MLX)/build
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_B)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: bonus all clean fclean re libft mlx42
