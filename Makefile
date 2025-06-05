# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 15:36:13 by leoaguia          #+#    #+#              #
#    Updated: 2025/06/05 19:48:53 by leoaguia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
SRC = main.c map.c
SRC_BONUS = main_bonus.c map_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS: .c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm
RM = rm -rf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
