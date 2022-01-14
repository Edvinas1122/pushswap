# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2022/01/14 23:47:14 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN = bin/ #OUTPUT DIR#
#---- Main program -------------------------------------------------#
MAIN_FILE = push_swap.c
MEDIUM_FILES = confirm_add.c input_var.c ft_lst_swap.c ft_lst_push.c \
			ft_lst_rotate.c ft_lst_rotate_rv.c
MEDIUM_FILES_DIR = src/medium/
MEDIUM = $(addprefix $(MEDIUM_FILES_DIR),$(MEDIUM_FILES))
ALG_FILES = set_index.c utils.c radix.c
ALG_FILES_DIR = src/algorithm/
ALG = $(addprefix $(ALG_FILES_DIR),$(ALG_FILES))
FLAG = -Wall -Wextra -Werror
COMPILE_FILES = $(MAIN_FILE) $(MEDIUM) $(ALG)
#------Libraries--------------------
LIBFT_FILES = libft.h libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
#------Other programs------------------
SORT_FILE = src/bonus/sort_read.c
BRUTE_FILE = src/bonus/brute_force.c
TEST_FILE = src/bonus/sort_line_reader.c
MEDIUM_BRUTE_FILES_DIR = src/bonus/medium_brute/
BRUTE = $(addprefix $(MEDIUM_BRUTE_FILES_DIR),$(MEDIUM_FILES))
MONITOR_FILES = src/bonus/print_feature_bonus.c
FILES_SORT = $(SORT_FILE) $(MEDIUM) $(MONITOR_FILES)
FILES_TEST = $(TEST_FILE) $(MEDIUM) $(MONITOR_FILES)
FILES_BRUTE = $(BRUTE_FILE) $(BRUTE)
GNL = $(CFLAG) GNL/get_next_line.h GNL/get_next_line.c GNL/get_next_line_utils.c
#---- Update above ------------------------------------------------#

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	OUT_NAME = push_swap_mac
	OUT_NAME_SORT = stack_sort_game_mac
	OUT_NAME_BRUTE = brute_force_mac
	OUT_NAME_TEST = tester_mac
	CFLAG = -I
else
	OUT_NAME = push_swap_Linux
	OUT_NAME_SORT = stack_sort_game_Linux
	OUT_NAME_BRUTE = brute_force_Linux
endif

all: $(OUT_NAME)

$(OUT_NAME):
	make bonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(COMPILE_FILES) $(CFLAG) $(LIBFT) -o $(OUT_NAME)
	
re:
	rm $(OUT_NAME)
	make bonus -C $(LIBFT_DIR)
	gcc  $(FLAG) $(COMPILE_FILES) $(CFLAG) $(LIBFT) -o $(OUT_NAME)

sort:
	make bonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(FILES_SORT) $(CFLAG) $(LIBFT) -o $(OUT_NAME_SORT)
	test $(OUT_NAME_BRUTE) || rm $(BIN)$(OUT_NAME_SORT)
	mv $(OUT_NAME_SORT) $(BIN)

brute:
	make bonus -C $(LIBFT_DIR)
	gcc  $(FLAG) $(FILES_BRUTE) $(CFLAG) $(LIBFT) -o $(OUT_NAME_BRUTE)
	test $(OUT_NAME_BRUTE) || rm $(BIN)$(OUT_NAME_BRUTE)
	mv $(OUT_NAME_BRUTE) $(BIN)

tester:
	make bonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(GNL) $(FILES_TEST) $(CFLAG) $(LIBFT) -o $(OUT_NAME_TEST)
	test $(OUT_NAME_BRUTE) || rm $(BIN)$(OUT_NAME_TEST)
	mv $(OUT_NAME_TEST) $(BIN)

printer:
	make bonus -C $(LIBFT_DIR)
	gcc  $(FLAG) $(COMPILE_FILES) $(MONITOR_FILES) $(CFLAG) $(LIBFT) -o $(OUT_NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)

.PHONY:			all re libup
