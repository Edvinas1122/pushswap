# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2022/01/15 12:29:45 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Main program -------------------------------------------------#
MAIN_FILE = push_swap.c
OUT_NAME = push_swap
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
LIBFT_DIR = src/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
#---- Update above ------------------------------------------------#

OS:= $(shell uname -s)
ifeq ($(OS),Darwin)
	CFLAG = -I
endif

all: $(OUT_NAME)

$(OUT_NAME):
	make bonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(COMPILE_FILES) $(CFLAG) $(LIBFT) -o $(OUT_NAME)
	
re:
	rm $(OUT_NAME)
	make bonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(COMPILE_FILES) $(CFLAG) $(LIBFT) -o $(OUT_NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)

.PHONY:			all re libup