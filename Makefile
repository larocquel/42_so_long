# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:06:58 by leoaguia          #+#    #+#              #
#    Updated: 2025/06/10 18:31:36 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT NAME
NAME = so_long
NAME_BONUS = so_long_bonus

# PATHS
SRC_DIR = ./src
INCLUDES = ./includes
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

# COMPILATION
CC = cc
C_FLAGS = -g -Wall -Wextra -Werror
LIB_FLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

# FILES
SRC = $(SRC_DIR)/main.c \
$(SRC_DIR)/game_loop.c \
$(SRC_DIR)/utils.c \
$(SRC_DIR)/input.c

# OBJECTS
OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

# RULES
all: $(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(C_FLAGS) $(LIB_FLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(C_FLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	if [ -d "$(MLX_DIR)" ]; then \
		make clean -C $(MLX_DIR) --no-print-directory; \
	fi

	@echo "Cleaning Objects!"

fclean: clean
	@rm -rf $(NAME)
	if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi

	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re
