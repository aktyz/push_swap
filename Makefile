# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/11/25 16:29:38 by zslowian         ###   ########.fr        #
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
	@git clone git@github.com:aktyz/libft.git
	@$(MAKE) -C ./libft

fclean: clean
	@cd ./libft && $(MAKE) fclean
	@rm -f $(NAME)
	@rm -fr $(OBJ_DIR)
	@rm -fr ./libft
	@rm ./libft.a
	@rm ./headers/libft.h
	@rm ./run_test
	@rm ./run_debug

clean:
	@rm -f $(OBJ)

test: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c test/test_main.c -o obj/test_main.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_check_test.c -o obj/heap_check_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_cost_calculation_test.c -o obj/heap_cost_calculation_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_getters_test.c -o obj/heap_getters_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_reverse_rotate_test.c -o obj/heap_reverse_rotate_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_swap_test.c -o obj/heap_swap_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_utils_test.c -o obj/heap_utils_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_atof_test.c -o obj/push_swap_atof_test.o
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_utils_test.c -o obj/push_swap_utils_test.o
	$(CC) obj/heap_check.o obj/heap_check_test.o obj/heap_cost_calculation.o obj/heap_cost_calculation_test.o \
		obj/heap_getters.o obj/heap_getters_test.o obj/heap_print_utils.o obj/heap_reverse_rotate.o obj/heap_reverse_rotate_test.o \
		obj/heap_rotate.o obj/heap_swap.o obj/heap_swap_test.o obj/heap_utils.o obj/heap_utils_test.o obj/push_swap_utils.o \
		obj/push_swap_utils_test.o obj/test_main.o obj/push_swap_atof.o obj/push_swap_atof_test.o ./libft.a -o run_test

debug: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c test/test_main.c -o obj/test_main.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_check_test.c -o obj/heap_check_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_cost_calculation_test.c -o obj/heap_cost_calculation_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_getters_test.c -o obj/heap_getters_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_reverse_rotate_test.c -o obj/heap_reverse_rotate_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_swap_test.c -o obj/heap_swap_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/heap_utils_test.c -o obj/heap_utils_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_atof_test.c -o obj/push_swap_atof_test.o -g
	$(CC) $(CFLAGS) $(INCLUDES) -c test/push_swap_utils_test.c -o obj/push_swap_utils_test.o -g
	$(CC) obj/heap_check.o obj/heap_check_test.o obj/heap_cost_calculation.o obj/heap_cost_calculation_test.o \
		obj/heap_getters.o obj/heap_getters_test.o obj/heap_print_utils.o obj/heap_reverse_rotate.o obj/heap_reverse_rotate_test.o \
		obj/heap_rotate.o obj/heap_swap.o obj/heap_swap_test.o obj/heap_utils.o obj/heap_utils_test.o obj/push_swap_utils.o \
		obj/push_swap_utils_test.o obj/test_main.o obj/push_swap_atof.o obj/push_swap_atof_test.o ./libft.a -o run_debug -g

re: fclean all

.PHONY: all clean fclean libft re
