# so_long


Para acessar a versão em português deste README [clique aqui](https://github.com/andersonhsporto/ft-so_long/blob/main/README-pt-br.md).
To read this file in English click [here](https://github.com/andersonhsporto/ft-so_long/blob/main/README.md).

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/42.png" width="600px" alt="42"/><br>
</p>


## Опис

Проект common core-у школи 42. Ціллю цього проекту є створеня доказу концепту 2D гри з використанням [MinilibX](https://github.com/42Paris/minilibx-linux) Графічної бібліотеки І такоож ANSI C мови програмування.

Цей проект - проста гра де гравець: має зібрати всі предмети на карті та дійти до виходу, може рухатися лише вертикально та горизонтально, грає на карті, що оточена стінами, має пусті місця, предмети і виходи, а також зазнає поразки якщо натикається на ворога.

### MLX

MinilibX це проста X-Window API программування в C, створена для студентів та яка підходить для початківців.

## Стилізація коду

Стилізація коду в цьому проекті це [Norminette](https://github.com/42School/norminette)
створена школою 42 та використовується в усіх проектах мови програмування C пов'язаних зі школою 42.


<br>


## Встановлення

Перед тим як компілювати проект дуже важливо встановити бібліотеку MLX, гайд може бути знайдений за посиланням: [MinilibX](https://github.com/42Paris/minilibx-linux).


Цей проект також використовує зовнішню бібліотеку [Libft](https://github.com/andersonhsporto/ft-libft),
так само розроблену в 42 curriculum. Для того щоб заклонити цю бібліотеку потрібно використати команду:

```sh
git clone --recursive https://github.com/andersonhsporto/ft-so_long.git
```

**<em> Ця команда заклонить вам цей проект та сабмодуль Libft </em>**


</br>

Цей проект поділено на дві частини - **обов'язкова** та **бонусна**.


Щоб скомпілювати **обов'язкову** частину (рухи персонажа та збирання предметів) використовуйте:
```sh
make
```

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-16.gif" width="800px" alt="mandatory"/><br>
</p>

Щоб скомпілювати **бонусну** частину (анімації, рухи ворогів та підрахунок рухів персонажа) використовуйте:

```sh
make bonus
```
<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-23.gif" width="400px" alt="bonus"/><br>
</p>

## Використання

Після компіляції проекта, ваш виконуваний файл **so_long** буде створено. Для запуску гри виповніть ваш виконуваний файл, передаючи вашу карту як аргумент:

Приклад:

```sh
./so_long map.ber
```
**<em> Деякі карти та карти використані для генерації header image розташовані в папці maps </em>**


## Посилання

* [Harm Smits - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX](https://github.com/42Paris/minilibx-linux)


## Контактна інформація

Якщо у вас є якісь питаннґ, ідеї або критика, будьте ласкаві зв'язатися зі мною через [email](mailto:anderson.higo2@gmail.com)
або ж [LinkedIn](https://www.linkedin.com/in/andersonhsporto/). Відгуки завжди умісні =D

### За переклад відповідав [Yurii Arutiunov](https://github.com/yarutiun)