NAME =	so_long
NAME_BONUS = so_long_bonus

CC 	 =	clang

INCLUDE = -I ./includes

CFLAGS = -Wall -Wextra -Werror  $(INCLUDE)

SOURCE =./source/
MOVE =	mov/
GNL = 	gnl/

SOURCE_B =./source_bonus/
MOVE_B =	mov/

GNSRC = 	$(addprefix $(GNL), \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
)

MSRC =		$(addprefix $(MOVE), \
		mov_left.c mov_right.c mov_up.c mov_down.c mov_utils.c \
)

A_SRC =		$(addprefix $(SOURCE), \
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

OBJ = $(SRC:%.c=%.o)

OBJ_B =	$(SRC_B:%.c=%.o)

LIB_FLAGS =	./libft/libft.a -lXext -lX11 ./mlx/libmlx.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make -C ./mlx
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJ_B)
	rm -rf $(NAME)
	make -C ./mlx
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ_B) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_B)
	rm -rf ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make clean  -C ./mlx
	make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re


c:
	rm -rf ./a.out
	$(CC) $(FLAGS) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	./a.out ./map/medium.ber

valgrind:
	rm -rf ./a.out
	$(CC) -g3 $(FLAGS) $(INCLUDE) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	valgrind --leak-check=full --show-leak-kinds=all ./a.out ./map/medium.ber

b:
	rm -rf ./a.out
	$(CC) -O3 $(FLAGS) $(INCLUDE) $(SRC_B) $(LIB_FLAGS)
	./a.out ./map/medium_fire.ber

bvalgrind:
	rm -rf ./a.out
	$(CC) -g $(FLAGS) $(INCLUDE) $(SRC_B) $(LIB_FLAGS)
	valgrind --leak-check=full --show-leak-kinds=all ./a.out ./map/medium_fire.ber

push: fclean
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push