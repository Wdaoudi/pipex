NAME = printf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

#Sources

SRC =  ft_printf.c \
        write.c \
        write2.c \

OBJ = $(SRC:.c=.o)

all:  $(NAME)

$(NAME):    $(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"

%.o: %.c
			@echo "Compiling: $<"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -f *.o
			@echo "ft_printf object files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "ft_printf executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

.PHONY:		all clean fclean re norm