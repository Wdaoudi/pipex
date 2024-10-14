# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Directories
SRC_DIR = src
LIBFT_DIR = libft

# Source files
SRC = $(SRC_DIR)/pathing.c $(SRC_DIR)/pipex.c $(SRC_DIR)/check.c $(SRC_DIR)/utils.c \
      $(SRC_DIR)/parsing.c $(SRC_DIR)/exec.c $(SRC_DIR)/opening.c $(SRC_DIR)/here_doc.c \

# Object files
OBJ = $(SRC:.c=.o)

# Names
NAME = pipex

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

# Rules
all: $(LIBFT) $(NAME) 

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus