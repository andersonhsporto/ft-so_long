EXTRA_PATH_METADATA = {'./.mlx': {'path': '.mlx'}}

NAME =	so_long

CC 	 =	clang

FLAGS =	-Wall -Wextra -Werror  $(INCLUDE)

SOURCE =./source/
MOVE =	mov/
GNL = 	gnl/

SOURCE_B =./source_bonus/
MOVE_B =	mov/

GNSRC = $(addprefix $(GNL), \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
)

MSRC =	$(addprefix $(MOVE), \
		mov_left.c mov_right.c mov_up.c mov_down.c mov_utils.c \
)

A_SRC =	$(addprefix $(SOURCE), \
		$(MSRC) \
		so_long.c window.c images.c map.c \
		map_update.c \
)

MSRC_B =	$(addprefix $(MOVE_B), \
		mov_left_bonus.c mov_right_bonus.c mov_up_bonus.c mov_down_bonus.c mov_utils_bonus.c \
)

A_SRC_B =	$(addprefix $(SOURCE_B), \
		$(MSRC_B) \
		so_long_bonus.c window_bonus.c images_bonus.c map_bonus.c \
		map_update_bonus.c animation_bonus.c enemy_bonus.c \
		init_bonus.c destroy_bonus.c \
)

SRC =	$(A_SRC) $(GNSRC)

SRC_B = $(A_SRC_B) $(GNSRC)

OBJ =	$(SRC:%.c=%.o)

OBJ_B =	$(SRC_B:%.c=%.o)

INCLUDE =	-I ./includes

LIB_FLAGS =	./libft/libft.a -lXext -lX11 ./.mlx/libmlx.a

.PHONY: all clean fclean re bonus push c clang

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./.mlx
	make bonus -C ./libft
	$(CC) $(FLAGS)  $(OBJ) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_B)
	rm -rf ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make clean  -C ./.mlx
	make fclean -C ./libft

re: fclean all

bonus: fclean $(OBJ_B)
	make -C ./mlx
	make bonus -C ./libft
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ_B) $(LIB_FLAGS) -o $(NAME)

c:
	rm -rf ./a.out
	$(CC) $(FLAGS) $(INCLUDE) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	./a.out ./teste.ber

clang: c

valgrind:
	rm -rf ./a.out
	$(CC) -g3 $(FLAGS) $(INCLUDE) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	valgrind --leak-check=full --show-leak-kinds=all ./a.out ./teste.ber


push:
	git add .
	@read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

b:
	rm -rf ./a.out
	$(CC) $(FLAGS) $(INCLUDE) $(SRC_B) $(LIB_FLAGS) ./libft/libft.a
	./a.out ./teste.ber

bvalgrind:
	rm -rf ./a.out
	$(CC) -g3 $(FLAGS) $(INCLUDE) $(SRC_B) $(LIB_FLAGS) ./libft/libft.a
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out ./teste.ber