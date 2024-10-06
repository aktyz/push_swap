# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/10/06 20:40:00 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(wildcard $(OBJ_DIR)/*.o)

INCLUDES = -I headers

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c libft
	@cp ./libft/libft.a ./libft.a
	@cp ./libft/headers/libft.h	./headers/libft.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@ar cr $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

libft:
	$(MAKE) -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -fr $(DIR_OBJ)
	@rm -f test.out
	@rm ./libft.a
	@rm ./headers/libft.h
	@cd ./libft && $(fclean)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean libft re test
