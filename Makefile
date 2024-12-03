NAME = cube3d
NAME_BONUS = fdf_bonus
FLAGS = -Wall -Wextra -Werror -I./include/
LFLAGS = -L./include/Libft -lft -L./include/MLX42/ -lmlx42 -Iinclude -lglfw -ldl -pthread -lm -no-pie#-L"/Users/jose-gon/.brew/opt/glfw/lib/" 
#LFLAGS = -L./include/Libft -lft -L./include/MLX42/ -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

FILES = cube3d.c

B_FILES =

SRC_DIR = src
SRC_B = src_bonus
OBJ_DIR = obj
SOURCES = $(FILES:%=$(SRC_DIR)/%)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
B_SOURCES = $(B_FILES:%=$(SRC_B)/%)
B_OBJECTS = $(patsubst $(SRC_B)/%.c, $(OBJ_DIR)/%.o, $(B_SOURCES))

all: libft mlx42 $(NAME)

libft:
	@$(MAKE) -C ./include/Libft

mlx42:
	@$(MAKE) -C ./include/MLX42

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

bonus: libft mlx42 $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_B)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C ./include/MLX42 clean
	@$(MAKE) -C ./include/Libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C ./include/MLX42 fclean
	@$(MAKE) -C ./include/Libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: bonus all clean fclean re mlx42 libft
