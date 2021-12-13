# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 20:25:25 by joeduard          #+#    #+#              #
#    Updated: 2021/12/13 12:43:09 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
INCLUDES = includes
HEADERS := $(INCLUDES)/push_swap.h
INCLUDES := $(addprefix -I, $(INCLUDES))


SRC_FILES = actions.c check_args.c do_print_actions.c exit.c ft_itob.c \
			is_integer.c ps_lst.c push_swap_long.c push_swap_short.c push_swap.c \
			quick_sort.c sort_stack.c stack_operations.c \
			
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFLAGS = -L$(LIBFT_DIR) -lft

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes  

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[32mBuilding the executable file...\033[0m"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $@
	@echo "\033[32mDone!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p obj

run: all
	$(VALGRIND) ./$(NAME) 1 2 3 4 5

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
	@echo "\033[31mExecutable and objects cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus