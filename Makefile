#EXTRA_PATH_METADATA = {'so_long/.mlx': {'path': '.mlx'}}

NAME =	so_long

CC 	 =	clang

FLAGS =	-Wall -Wextra -Werror -lm -g $(INCLUDE)

SOURCE =./source/
MOVE =	mov/
GNL = 	gnl/

GNSRC = $(addprefix $(GNL), \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
)

MSRC =	$(addprefix $(MOVE), \
		mov_left.c mov_right.c mov_up.c mov_down.c mov_utils.c \
)

A_SRC =	$(addprefix $(SOURCE), \
		$(MSRC) \
		main.c window.c key.c images.c map.c \
		map_update.c \
)

SRC = $(A_SRC) $(GNSRC)

OBJ =	$(SRC:%.c=%.o)

INCLUDE =	-I ./includes

LIB_FLAGS =	./libft/libft.a -lmlx -lXext -lX11

.PHONY: all clean fclean re push c clang

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C ./libft
	$(CC) -g3 $(FLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

push:
	git add .
	git commit -m "updated"
	git push

c:
	rm -rf ./a.out
	$(CC) $(FLAGS) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	./a.out ./teste.ber

clang: c

valgrind:
	rm -rf ./a.out
	$(CC) $(FLAGS) $(SRC) $(LIB_FLAGS) ./libft/libft.a
	valgrind --leak-check=full --show-leak-kinds=all ./a.out ./teste.ber

