# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/10/13 19:10:14 by zslowian         ###   ########.fr        #
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
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g

$(NAME): $(OBJ)
	$(CC) $(OBJ) ./libft.a -o $(NAME) -g

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
	@rm ./run_test
	@rm ./run_debug

clean:
	@rm -f $(OBJ)

test: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c test/test_main.c -o obj/test_main.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_getters_test.c -o obj/heap_getters_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_operations_test.c -o obj/heap_operations_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_checkers_test.c -o obj/heap_checkers_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_utils_test.c -o obj/push_swap_utils_test.o -g
	$(CC) obj/test_main.o obj/push_swap_utils_test.o obj/heap_checkers_test.o obj/heap_getters_test.o obj/heap_operations_test.o obj/push_swap_utils.o obj/heap_utils.o obj/heap_print_utils.o obj/heap_getters.o ./libft.a -o run_test

debug: $(OBJ) test
	$(CC) $(CFLAGS) $(INCLUDES) -c test/test_main.c -o obj/test_main.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_getters_test.c -o obj/heap_getters_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_operations_test.c -o obj/heap_operations_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_checkers_test.c -o obj/heap_checkers_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_utils_test.c -o obj/push_swap_utils_test.o -g
	$(CC) obj/test_main.o obj/push_swap_utils_test.o obj/heap_checkers_test.o obj/heap_getters_test.o obj/heap_operations_test.o obj/push_swap_utils.o obj/heap_utils.o obj/heap_print_utils.o obj/heap_getters.o ./libft.a -o run_debug -g

re: fclean all

.PHONY: all clean fclean libft re
