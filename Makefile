# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2021/12/20 23:52:16 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Update bellow -----------------------------------------------#

FILES = push_swap.c confirm_add.c input_var.c
OBJ = push_swap.o confirm_add.o	input_var.o
LIBFT_DIR = libft/
FLAG = -Wall -Wextra -Werror
HEADER = push_swap.h

#---- Update above ------------------------------------------------#

OUT_NAME = push_swap # client program name output #


all:
	test -f $(LIBFT_DIR)libft.a || make re -C $(LIBFT_DIR)
	gcc -c $(FILES)
	gcc $(OBJ) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)
re:
	rm $(OUT_NAME) 
	test -f $(LIBFT_DIR)libft.a || make re -C $(LIBFT_DIR)
	gcc -c $(FILES)
	gcc $(OBJ) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)