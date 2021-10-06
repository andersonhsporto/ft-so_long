#EXTRA_PATH_METADATA = {'so_long/.mlx': {'path': '.mlx'}}

NAME = so_long

CC = clang

FLAGS = -Wall  -Wextra -lm  $(INCLUDE)

SOURCE = ./source/

SRC = $(addprefix $(SOURCE), \
	main.c window.c \
)

INCLUDE = -I ./includes

LIB_FLAGS = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make all -C ./mlx
	make all -C ./libft
	$(CC) -g3 -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)
	rm $(OBJ)

#skiperror:
#	gcc -o $(NAME) $(SRC) -g $(LIB)

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
	$(CC) $(FLAGS)  triangulo.c ./mlx/libmlx_Linux.a ./mlx/libmlx.a $(LIB_FLAGS) ./libft/libft.a
	./a.out

square:
	rm -rf ./a.out
	$(CC) $(FLAGS)  quadrado.c ./mlx/libmlx_Linux.a ./mlx/libmlx.a $(LIB_FLAGS) ./libft/libft.a
	./a.out

push:
	git add .
	git commit -m "updated"
	git push
