################################################################################
################################################################################
################################################################################

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

################################################################################
################################################################################
################################################################################

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -lX11 -g3

MLX			=   -lmlx -lXext -lX11

LIB_FLAGS	=	-L ./0-libft -lft

################################################################################
################################################################################
################################################################################

INCLUDE		=	-I ./includes

SOURCE		=	./source/

SOURCE_B	=	./source_bonus/

################################################################################
################################################################################
################################################################################

MAP =		$(addprefix 0-map/, \
		0_map.c 1_map_update.c 2_map_utils.c \
		3_map_render_player.c \
)

WINDOW =	$(addprefix 1-window/, \
		0_window.c 1_screen_validations.c \
)

MOVE =		$(addprefix 2-movements/, \
		mov_left.c mov_right.c mov_up.c mov_down.c mov_utils.c \
)

VALIDATION =	$(addprefix 3-validation/, \
		0_file_reader.c 1_map_validation.c \
)

A_SRC =		$(addprefix $(SOURCE), \
		$(MOVE) $(MAP) $(WINDOW) $(VALIDATION) \
		0_endgame.c 1_images.c \
		so_long.c \
)

################################################################################
############################## BONUS FILES #####################################
################################################################################

ANIMATION_B	= 	$(addprefix 4-animation/, \
		animation_bonus.c destroy_bonus.c enemy_bonus.c \
)

MAP_B		= 	$(addprefix 0-map/, \
		0-map_bonus.c 1_map_update_bonus.c 2_map_utils_bonus.c map_update_bonus.c 3_map_render_player.c \
)


WINDOW_B	=	$(addprefix 1-window/, \
		0_window_bonus.c 1_screen_validations.c \
)

MOVE_B		=	$(addprefix 2-movements/, \
		mov_left_bonus.c mov_right_bonus.c mov_up_bonus.c mov_down_bonus.c \
		mov_utils_bonus.c \
)

VALIDATION_B =	$(addprefix 3-validation/, \
		0_file_reader_bonus.c 1_map_validation_bonus.c \
)

A_SRC_B		=	$(addprefix $(SOURCE_B), \
		$(ANIMATION_B) $(MOVE_B) $(MAP_B) $(WINDOW_B) $(VALIDATION_B) \
		0_endgame_bonus.c 1_images_bonus.c 2_images_init_bonus.c \
		so_long_bonus.c \
)


################################################################################
################################################################################
################################################################################

SRC =	$(A_SRC)

SRC_B = $(A_SRC_B)

OBJ = $(SRC:%.c=%.o)

OBJ_B =	$(SRC_B:%.c=%_b.o)

################################################################################
################################################################################
################################################################################

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%.o)

%_b.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%_b.o)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make all -C ./0-libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(MLX) -o $(NAME)

$(NAME_BONUS): $(OBJ_B)
	rm -rf $(NAME)
	make all -C ./0-libft
	$(CC) $(CFLAGS) $(OBJ_B) $(LIB_FLAGS) $(MLX) -o $(NAME_BONUS)

################################################################################
################################################################################
################################################################################

clean:
	rm -rf $(OBJ) $(OBJ_B)
	rm -rf ./a.out
	make clean -C ./0-libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C ./0-libft

re: fclean all

re bonus: fclean bonus

.PHONY: all bonus clean fclean re

################################################################################
################################################################################
################################################################################
