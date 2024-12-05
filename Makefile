NAME = cube3D
MLX42 = ./lib/MLX42
#NAME_BONUS =
FLAGS = -Wall -Wextra -Werror -I./include/
LFLAGS = -L./lib/Libft -lft -L./lib/MLX42/build -lmlx42 -Iinclude -lglfw -ldl -pthread -lm -no-pie#-L"/Users/jose-gon/.brew/opt/glfw/lib/" 
#LFLAGS = -L./include/Libft -lft -L./include/MLX42/ -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

FILES = cube3D.c

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
	@$(MAKE) -C ./lib/Libft

mlx42:
	@cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4
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
	@$(MAKE) -C ./lib/Libft clean
	rm -rf $(MLX42)/build
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C ./lib/Libft fclean
	rm -rf $(MLX42)/build
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: bonus all clean fclean re libft
