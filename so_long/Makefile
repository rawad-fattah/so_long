NAME = so_long

SRC = src/so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
      src/map_validation.c src/game.c src/map_validation2.c src/free.c src/moves.c \
      src/dfs.c src/utils.c
OBJ := $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -Ilibft -Ift_printf -I./MinilibX

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = ./MinilibX
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

.PHONY: all clean fclean re libft ft_printf

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(MLX) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all
