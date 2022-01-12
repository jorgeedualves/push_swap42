# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 20:25:25 by joeduard          #+#    #+#              #
#    Updated: 2022/01/11 22:13:29 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
INCLUDES = includes
HEADERS := $(INCLUDES)/push_swap.h
INCLUDES := $(addprefix -I, $(INCLUDES))


SRC_FILES = actions.c check_args.c exit.c ft_itob.c is_integer.c \
			ps_lst.c push_swap_long.c push_swap_short.c push_swap_short2.c push_swap.c \
			quick_sort.c \
			
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

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	@echo "\033[32mBuilding the executable file...\033[0m"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $@
	@echo "\033[32mDone!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run: all
	$(VALGRIND) ./$(NAME) 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 2 1 0 -2 -1 | wc - l

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
	@echo "\033[31mExecutable and objects cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus