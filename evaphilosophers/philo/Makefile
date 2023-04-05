SRCS = philo.c input.c routine.c checker.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CLFAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = philo

INCLUDE = -I include

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all clean