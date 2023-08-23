# so_long

To read this file in English click [here](https://github.com/andersonhsporto/ft-so_long/blob/main/README.md)

Щоб прочитати цей файл українською, перейдіть за посиланням [here](https://github.com/andersonhsporto/ft-so_long/blob/main/README-uk.md)

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/42.png" width="600px" alt="42"/><br>
</p>


## Descrição

Projeto da trilha de fundamentos da escola 42. O objetivo é criar uma prova de conceito de um jogo 2D utilizando a biblioteca gráfica MinilibX e a linguagem ANSI C.

Este projeto é um jogo simples em que o jogador deve coletar todos os itens no mapa e chegar à saída. O jogador só pode se mover horizontalmente e verticalmente, o mapa é composto por paredes, espaços vazios, itens colecionáveis e a saída. O jogador perde se colidir com um inimigo.


### MLX

O MinilibX é uma simples API de programação de X-Window em C, projetada para estudantes e adequada para iniciantes.

## Estilo de código

O estilo de código utilizado neste projeto é o [Norminette](https://github.com/42School/norminette), criado pela escola 42 e usado em todos os projetos relacionados à linguagem ANSI C no contexto da escola.



<br>


## Instalação

Antes de compilar o projeto, é necessário instalar a biblioteca MLX. Um guia pode ser encontrado no repositório da [MinilibX](https://github.com/42Paris/minilibx-linux).

Este projeto também usa a biblioteca externa [Libft](https://github.com/andersonhsporto/ft-libft), também desenvolvida durante a trilha de fundamentos da escola 42. Para clonar este projeto e esta biblioteca, use o seguinte comando:

```sh
git clone --recursive https://github.com/andersonhsporto/ft-so_long.git
```

**<em> este comando irá clonar o projeto e o submódulo Libft </em>**


</br>

Este projeto é dividido em duas partes, o **mandatório** e o **bônus**.


Para compilar a parte **mandatório** (movimentação do personagem e coleta de itens) use:
```sh
make
```

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-16.gif" width="800px" alt="mandatory"/><br>
</p>

Para compilar a parte **bônus** (animação, contador de movimentos e inimigos) use:

```sh
make bonus
```
<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-23.gif" width="400px" alt="bonus"/><br>
</p>

## Utilização

Depois de compilar o projeto, o arquivo executável com o nome **so_long** será criado, para executar o jogo chame o executável utilizando o caminho do mapa como argumento:

Exemplo:

```sh
./so_long map.ber
```
**<em> alguns mapas e o mapa utilizado para gerar a imagem do cabeçalho podem ser encontrados na pasta maps </em>**


## Referências

* [Harm Smits - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX](https://github.com/42Paris/minilibx-linux)


## Informações de contato

Se você tiver alguma dúvida, sugestão ou crítica, entre em contato comigo através do [e-mail](mailto:anderson.higo2@gmail.com) ou pelo [LinkedIn](https://www.linkedin.com/in/andersonhsporto/). Feedbacks são sempre bem-vindos =D


