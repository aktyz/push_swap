# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/10/06 19:56:17 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR_SRC = src
DIR_OBJ = obj
DIR_TEST = test

SUBDIR = stack

SRC_DIR = $(foreach dir, $(SUBDIR), $(addprefix $(DIR_SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIR), $(addprefix $(DIR_OBJ)/, $(dir)))
SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ = $(subst $(DIR_SRC), $(DIR_OBJ), $(SRC:.c=.o))
TEST_SRC = $(wildcard $(DIR_TEST)/*.c)

INCLUDES = -I headers

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c libft
	@cp ./libft/libft.a ./libft.a
	@cp ./libft/headers/libft.h	./headers/libft.h
	@mkdir -p $(DIR_OBJ) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@ar cr $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

libft:
	$(MAKE) -C ./libft

fclean: clean
	@rm ./libft.a
	@rm ./headers/libft.h
	@rm -f $(NAME)
	@rm -fr $(DIR_OBJ)
	@rm -f test.out
	@cp ./libft && $(fclean)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean libft re test
