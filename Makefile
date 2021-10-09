#EXTRA_PATH_METADATA = {'so_long/.mlx': {'path': '.mlx'}}

NAME =	so_long

CC =	clang

FLAGS =	-Wall -Wextra -lm  $(INCLUDE) 

SOURCE =./source/

MOVE =	mov/

MSRC =	$(addprefix $(MOVE), \
		mov_left.c mov_right.c mov_up.c mov_down.c \
)

SRC =	$(addprefix $(SOURCE), \
		$(MSRC) \
		main.c window.c key.c images.c map.c \
)

OBJ = $(SRC:%.c=%.o)

INCLUDE = -I ./includes

LIB_FLAGS = ./libft/libft.a -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	make all -C ./mlx
	make all -C ./libft
	$(CC) -g3 -fsanitize=address $(FLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)

#skiperror:
#	gcc -o $(NAME) $(SRC) -g $(LIB) () ()
clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make clean -C ./mlx
	make fclean -C ./libft

re: fclean all

clang:
	rm -rf ./a.out
	$(CC) $(FLAGS)  $(SRC) ./mlx/libmlx.a $(LIB_FLAGS) ./libft/libft.a
	./a.out

tri:
	rm -rf ./a.out
	$(CC) $(FLAGS)  ./extra/triangulo.c ./mlx/libmlx_Linux.a ./mlx/libmlx.a $(LIB_FLAGS) ./libft/libft.a
	./a.out

square:
	rm -rf ./a.out
	$(CC) $(FLAGS)  ./extra/quadrado.c ./mlx/libmlx_Linux.a ./mlx/libmlx.a $(LIB_FLAGS) ./libft/libft.a
	./a.out

push:
	git add .
	git commit -m "updated"
	git push

fim: $(OBJ)
	$(CC) -g3 -fsanitize=address $(FLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	./so_long

.PHONY: all clean fclean re tri square push fim