NAME = cub3D
MLX = ./lib/MLX42
LIBFT = ./lib/Libft
#NAME_BONUS =
FLAGS = -g -Wall -Wextra -Werror -I./include/
LFLAGS = -L$(LIBFT) -lft -L$(MLX)/build -lmlx42 -Iinclude -lglfw -ldl -pthread -lm -no-pie#-L"/Users/jose-gon/.brew/opt/glfw/lib/" 
#LFLAGS = -L$(LIBFT) -lft -L$(MLX) -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

FILES = cube3D.c init_cub.c parse_map.c valid_map.c parse_color.c parse_check.c error.c \
square_map.c mlx_run.c mlx_keys.c cube_it.c

#B_FILES =

SRC_DIR = src
#SRC_B = src_bonus
OBJ_DIR = obj
SOURCES = $(FILES:%=$(SRC_DIR)/%)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
#B_SOURCES = $(B_FILES:%=$(SRC_B)/%)
#B_OBJECTS = $(patsubst $(SRC_B)/%.c, $(OBJ_DIR)/%.o, $(B_SOURCES))

all: libft mlx42 $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

mlx42:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
#	@$(MAKE) -C ./include/

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

# bonus: libft $(NAME_BONUS)

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
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: bonus all clean fclean re libft
