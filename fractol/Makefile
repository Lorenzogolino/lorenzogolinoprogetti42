# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgolino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 15:56:54 by lgolino           #+#    #+#              #
#    Updated: 2023/07/03 15:56:58 by lgolino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/algos.c srcs/event.c srcs/plane.c srcs/strs.c
COMP = gcc -Wall -Wextra -Werror -Ofast
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fractal
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(COMP) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(COMP) $(OBJS) $(MLX) -o $(NAME)
	@echo "\033[0;94m./${NAME} has been created\033[0m"

clean :
	@rm -rf $(OBJS)
	@echo "\033[0;35mOBJS deleted\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[0;35m./${NAME} deleted\033[0m"

re : fclean all
	@echo "\033[0;94mRESTART\033[0m"

.PHONY: clean fclean re all
