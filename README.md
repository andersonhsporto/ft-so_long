# so_long


Para acessar a versão em português deste README [clique aqui](https://github.com/andersonhsporto/ft-so_long/blob/main/README-pt-br.md).
Щоб прочитати цей файл українською, перейдіть за посиланням [here](https://github.com/andersonhsporto/ft-so_long/blob/main/README-uk.md).

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/42.png" width="600px" alt="42"/><br>
</p>


## Description

Project of the 42 school common core curriculum. The goal is to create a proof of concept of a 2D game using the [MinilibX](https://github.com/42Paris/minilibx-linux) graphic library and the ANSI C language.

This project is a simple game where the player must collect all the items on the map and reach the exit, the player can only move horizontally and vertically, the map is composed of walls, empty spaces, collectible items and the exit, the player loses if he collides with an enemy.

### MLX

The MinilibX is a simple X-Window programming API in C, designed for students, suitable for beginners.

## Code style

The code style used in this project is the [Norminette](https://github.com/42School/norminette) 
created by the 42 school and used in all related ANSI C projects in the context of the school.


<br>


## Installation

Before compiling the project it is necessary to install MLX library a guide can be found
in the [MinilibX](https://github.com/42Paris/minilibx-linux) repository.


This project also uses the external library [Libft](https://github.com/andersonhsporto/ft-libft) 
also developed in the 42 school curriculum, to clone this project and this library use the command:

```sh
git clone --recursive https://github.com/andersonhsporto/ft-so_long.git
```

**<em> this command will clone the project and the Libft submodule </em>**


</br>

This project is divided into two parts, the **mandatory** and the **bonus**.


To compile the **mandatory** part (character movement and item collection) use:
```sh
make
```

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-16.gif" width="800px" alt="mandatory"/><br>
</p>

To compile the **bonus** part (animation, movement counter and enemies) use:

```sh
make bonus
```
<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-23.gif" width="400px" alt="bonus"/><br>
</p>

## Usage

After compiling the project, the executable file with the name **so_long** will be created, to run the game call the executable passing the map as an argument:

Example:

```sh
./so_long map.ber
```
**<em> some maps and the map used to generate the header image can be found in the maps folder </em>**


## References

* [Harm Smits - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX](https://github.com/42Paris/minilibx-linux)


## Contact Information

If you have any questions, suggestions, or critiques, please contact me using [email](mailto:anderson.higo2@gmail.com)
or through [LinkedIn](https://www.linkedin.com/in/andersonhsporto/). feedbacks are always welcome =D
