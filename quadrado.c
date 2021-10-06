#include "./includes/so_long.h"

int renderMap(t_game *game);

//1 = parede, 0 = espaço vazio
int grid[MAP_NUM_ROWS][MAP_NUM_COLS] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

//iniciando nosso mapa
void map_init(t_game *game) {
	memcpy(game->map, grid, sizeof(int) * MAP_NUM_ROWS * MAP_NUM_COLS);
	renderMap(game);
}

//desenhando cada tile nosso, color1 = cor da borda (stroke), color2 = cor do tile
void draw_pixels_of_tile(t_game *game, int row, int col, int color1, int color2)
{
	int tile_row, tile_col;

	row *= TILE_SIZE;
	col *= TILE_SIZE;
	tile_row = 0;
	while (tile_row < TILE_SIZE)
	{
		tile_col = 0;
		while (tile_col < TILE_SIZE)
		{
			if (tile_row == TILE_SIZE - 1 || tile_col == TILE_SIZE - 1)
				game->img.data[(tile_row + row) * WINDOW_WIDTH + (tile_col + col)] = color1;
			else
				game->img.data[(tile_row + row) * WINDOW_WIDTH + (tile_col + col)] = color2;
			tile_col++;
		}
		tile_row++;
	}
}

void	init_img(t_game *game, int x, int y)
{
	game->img.path = "./img/zelda3.xpm";
	game->img.img_pointer = mlx_xpm_file_to_image
		(game->mlx, game->img.path, &x, &y);
	mlx_put_image_to_window
	(game->mlx, game->window_pointer, game->img.img_pointer, x, y);
}


//basicamente: percorre o mapa e se for parede (1) deixa
//tudo preto, senão faz pinta de branco com bordas pretas
int renderMap(t_game *game)
{
	int row, col;

	row = 0;
	while (row < MAP_NUM_ROWS)
	{
		col = 0;
		while (col < MAP_NUM_COLS)
		{
			if (game->map[row][col] == 1)
				//init_img(game, row, col);
				draw_pixels_of_tile(game, row, col, BLACK, BLACK);
			else
				draw_pixels_of_tile(game, row, col, BLACK, WHITE);
			col++;
		}
		row++;
	}

	return (1);
}

//função que realiza a colisão com as paredes
int hasWallAt(int x, int y) {
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) return 1;
	int mapGridIndexX = floor(x / TILE_SIZE);
	int mapGridIndexY = floor(y / TILE_SIZE);
	return grid[mapGridIndexY][mapGridIndexX] != 0;
}

//inicializando o player com dados iniciais
//o 3.14 pode ser substituido pela macro M_PI presente
//na lib <math.h>
void player_init(t_game *game) {
	game->player.x = WINDOW_WIDTH / 2;
	game->player.y = WINDOW_HEIGHT / 2;
	game->player.radius = 3;
	game->player.turnDirection = 0; // -1 se esquerda, +1 se direita
	game->player.walkDirection = 0; // -1 se trás, +1 se frente
	game->player.rotationAngle = 3.14 / 2;
	game->player.moveSpeed = 7.0;
	game->player.rotationSpeed = 2 * (3.14 / 180);
}

//essa função funciona igual a uma para desenhar um quadrado
//futuramente alterar para desenhar um círculo
void draw_player(t_game *game, int x, int y, int color)
{
    int dx;
    int dy;
 
    dy = 0;
    while (dy < PLAYER_TILE_SIZE)
    {
        dx = 0;
        while (dx < PLAYER_TILE_SIZE)
        {
            game->img.data[WINDOW_WIDTH * (y + dy) + (x + dx)] = color;
            dx++;
        }
        dy++;
    }
}

//função responsável por atualizar informações pertinentes a movimentação do player
void update(t_game *game) {
	float moveStep = game->player.walkDirection * game->player.moveSpeed;

	float newPlayerX = game->player.x + cos(game->player.rotationAngle) * moveStep;
	float newPlayerY = game->player.y + sin(game->player.rotationAngle) * moveStep;

	if (!hasWallAt(newPlayerX, newPlayerY)) {
		game->player.x = newPlayerX;
		game->player.y = newPlayerY;
	}
}


//inicializando o mlx
void minilibx_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window_pointer = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Creating a 2D game!");
}

//inicializando nossa imagem
void img_init(t_game *game)
{
	game->img.img_pointer = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_pointer, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

//definindo o que deve acontecer sempre que soltamos a tecla
int	keyRelease(int keyCode, t_game *game) {
	if (keyCode == UP) {
		game->player.walkDirection = 0;
	} else if (keyCode == DOWN) {
		game->player.walkDirection = 0;
	} else if (keyCode == RIGHT) {
		game->player.turnDirection = 0;
		game->player.rotationAngle += game->player.turnDirection * game->player.rotationSpeed;
	} else if (keyCode == LEFT) {
		game->player.turnDirection = 0;
		game->player.rotationAngle += game->player.turnDirection * game->player.rotationSpeed;
	}

	return (1);
}

//definindo o que deve acontecer sempre que apertamos alguma tecla
int	keyPressed(int keyCode, t_game *game) {
	if (keyCode == UP) {
		game->player.walkDirection = 1;
		update(game);
	} else if (keyCode == DOWN) {
		game->player.walkDirection = -1;
		update(game);
	} else if (keyCode == RIGHT) {
		game->player.turnDirection = 1;
		game->player.rotationAngle += game->player.turnDirection * game->player.rotationSpeed;
	} else if (keyCode == LEFT) {
		game->player.turnDirection = -1;
		game->player.rotationAngle += game->player.turnDirection * game->player.rotationSpeed;
	} else if (keyCode == ESC) {
		exit(0);
	}

	return (1);
}

//função para desenhar a linha que indica a direção do jogador
int draw_line(t_game *game, int beginX, int beginY, int endX, int endY, int color) {
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;

	double pixelX = beginX;
	double pixelY = beginY;

	while (pixels) {
		game->img.data[WINDOW_WIDTH * (int)floor(pixelY) + (int)floor(pixelX)] = color;
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}

	return (1);
}

int draw_loop (t_game *game) {
	map_init(game);
	draw_line(game, game->player.x, game->player.y, game->player.x + cos(game->player.rotationAngle) * 30, game->player.y + sin(game->player.rotationAngle) * 30, RED);
	draw_player(game, game->player.x, game->player.y, RED);
	mlx_put_image_to_window(game->mlx, game->window_pointer, game->img.img_pointer, 0, 0);
	return 0;
}

int main(void)
{
	t_game game;

	minilibx_init(&game);
	img_init(&game);
	player_init(&game);
	mlx_hook(game.window_pointer, 2, 1L<<0, keyPressed, &game);
	mlx_hook(game.window_pointer, 3, 1L<<0, keyRelease, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);

	return (0);
}
