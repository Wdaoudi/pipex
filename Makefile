# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Directories
SRC_DIR = src
BONUS_DIR = bonus
LIBFT_DIR = libft

# Source files
SRC = $(SRC_DIR)/pathing.c $(SRC_DIR)/pipex.c $(SRC_DIR)/check.c $(SRC_DIR)/utils.c \
      $(SRC_DIR)/parsing.c $(SRC_DIR)/exec.c $(SRC_DIR)/opening.c

SRC_BONUS = $(BONUS_DIR)/pathingb.c $(BONUS_DIR)/pipexb.c $(BONUS_DIR)/checkb.c $(BONUS_DIR)/utilsb.c \
            $(BONUS_DIR)/parsingb.c $(BONUS_DIR)/execb.c $(BONUS_DIR)/openingb.c

# Object files
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Names
NAME = pipex
NAME_BONUS = pipex_bonus

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(LIBFT) $(NAME_BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus