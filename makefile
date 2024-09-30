NAME = pipex

LIBFT_DIR = libft
SRC_DIR = src
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -Wall -Wextra -Werror -g3
CC = cc
SRC = main.c ft_path.c ft_secure.c
OBJ = $(SRC:.c=.o)
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
