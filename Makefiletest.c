SRC = src/pathing.c src/pipex.c src/check.c  src/utils.c \
	src/parsing.c  src/exec.c src/opening.c \

SRC_BONUS = bonus/pathing.c bonus/pipex.c bonus/check.c  bonus/utils.c \
	bonus/parsing.c  bonus/exec.c bonus/opening.c \
#ajout

NAME = pipex

NAME_BONUS = pipex_bonus

LIBFT_DIR = libft
SRC_DIR = src
BONUS_DIR = bonus
#ajout

LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
CC = cc
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=o)
#ajout

INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME) 
#ajout

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus : $(LIBFT) $(NAME_BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
