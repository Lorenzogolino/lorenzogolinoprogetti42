NAME		= libftprintf.a
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c
RM			= rm -f
AR			= ar rcs
HEADER		= ft_printf.h

SRC_FILES	= ft_printfprova

SRC 		= ft_printf.c ft_printf_utils.c
OBJ 		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			# @echo "ft_printf compiled!"

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
# 			@echo "Compiling: $<"
# 			@$(CC) $(CFLAGS) $< -o $@

# $(OBJF):
# 			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ)
			@echo "ft_printf object files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "ft_printf executable files cleaned!"
			@echo "libft executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm