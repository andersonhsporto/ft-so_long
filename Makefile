NAME = so_long

CC = clang

FLAGS = -Wall -Wextra -Werror $(INCLUDE)

SRC = main.c

INCLUDE = -I ./includes

LIB = -L ./mlx -lmlx -lXext -lX11

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make all -C ./mlx
	$(CC) -g3 -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)

#skiperror:
#	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./mlx

fclean: clean
	rm -rf $(NAME)

re: fclean all

clang:
	$(CC) $(FLAGS)  $(SRC) ./mlx/libmlx_Linux.a ./mlx/libmlx.a $(LIB)
	./a.out
