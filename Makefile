# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/27 22:04:04 by lnagy             #+#    #+#              #
#    Updated: 2016/04/27 22:04:08 by lnagy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror -O3

NAME = fdf

SRC = main.c \
	printline.c \
	keys.c \
	map.c
	
OBJ = $(SRC:.c=.o)

MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

COMMIT = fast_push

all: $(NAME)

$(NAME): $(OBJ)
	@make -k -C libft
	@make -k -C minilibx_macos
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(MLX) -Llibft -lft
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@make clean -k -C libft
	@rm -f $(OBJ)
	@echo "$(NAME) *.o deleted"

fclean: clean
	@make fclean -k -C libft
	@make clean -k -C minilibx_macos
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

push: fclean
	@git add --all
	@git commit -m $(COMMIT)
	@git push

.PHONY: all, clean, fclean, re
