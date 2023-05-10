NAME = so_long

SRCS = ./src/so_long.c ./src/read_map.c ./src/print_map.c ./src/get_next_line.c \
			./src/get_next_line_utils.c ./src/key_press.c ./src/check_exit.c \
			./src/ft_free.c ./src/ft_itoa.c ./src/ft_calloc.c ./src/ft_bzero.c \
			./src/ft_memset.c ./src/ft_error.c

INCLUD = ./inc/so_long.h \
			./inc/mlx.h

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -MMD
LIB = -L. -lmlx -framework OpenGL -framework AppKit

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS2 = $(addsuffix .d, $(basename $(BONUS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
	@make -C ./mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(SRCS) $(LIB) -o $(NAME)

-include $(DEPS2)

clean:
			@make -C ./mlx clean
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}

fclean:
			@make -C ./mlx clean
			@${RM} ${OBJS}
			@${RM} ${DEPS} ${DEPS2}

re: fclean all

.PHONY: all clean fclean re
