# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/10/07 12:38:22 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INCLUDES = -I headers

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c libft
	@cp ./libft/libft.a ./libft.a
	@cp ./libft/headers/libft.h	./headers/libft.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) ./libft.a -o $(NAME)

all: $(NAME)

libft:
	@$(MAKE) -C ./libft

fclean: clean
	@cd ./libft && $(MAKE) fclean
	@rm -f $(NAME)
	@rm -fr $(OBJ_DIR)
	@rm -f test.out
	@rm ./libft.a
	@rm ./headers/libft.h

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean libft re
