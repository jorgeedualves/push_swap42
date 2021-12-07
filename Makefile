# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 20:25:25 by joeduard          #+#    #+#              #
#    Updated: 2021/12/06 10:13:47 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
INCLUDES = includes
HEADERS := $(INCLUDES)/push_swap.h
INCLUDES := $(addprefix -I, $(INCLUDES))


SRC_FILES = push_swap.c do_print_actions.c stack_operations.c actions.c sort_stack.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFLAGS = -L$(LIBFT_DIR) -lft

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

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

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
	@echo "\033[31mExecutable and objects cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus