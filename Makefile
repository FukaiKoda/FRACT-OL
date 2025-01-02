CC = cc

CFLAGS = -Wall -Wextra -Werror -I .

MLX_FLAGS = -L/home/habdella/include/minilibx-linux -lmlx -lXext -lX11 -lm

RM = rm -rf

SRC = main.c initial_check.c initialize.c events.c fractal_render.c math.c

OBJ = ${SRC:%.c=%.o}

NAME = fractol

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRC} ${MLX_FLAGS} -o $@

bonus: all

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all NAME clean fclean re
