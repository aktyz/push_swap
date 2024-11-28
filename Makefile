# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:42:02 by zslowian          #+#    #+#              #
#    Updated: 2024/11/28 15:32:28 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
TEST = run_test
DEBUG = run_debug

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = heap_check.c \
	heap_cost_calculation.c \
	heap_getters.c \
	heap_print_utils.c \
	heap_reverse_rotate.c \
	heap_rotate.c \
	heap_swap.c \
	heap_utils.c \
	push_swap_atof.c \
	push_swap_utils.c \
	push_swap.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

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
	@git submodule update --init --recursive
	@$(MAKE) -C ./libft

fclean: clean
	@cd ./libft && $(MAKE) fclean
	@rm -f $(NAME)
	@rm -fr $(OBJ_DIR)
	@rm -f ./libft.a
	@rm -f ./headers/libft.h
	@rm -f ./$(TEST)
	@rm -f ./$(DEBUG)

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
		obj/push_swap_utils_test.o obj/test_main.o obj/push_swap_atof.o obj/push_swap_atof_test.o obj/push_swap.o ./libft.a -o $(TEST)

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
		obj/push_swap_utils_test.o obj/test_main.o obj/push_swap_atof.o obj/push_swap_atof_test.o obj/push_swap.o ./libft.a -o $(DEBUG) -g

re: fclean all

.PHONY: all clean fclean libft re
