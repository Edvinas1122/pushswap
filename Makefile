# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2021/12/26 21:34:38 by emomkus          ###   ########.fr        #
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

#
#all:
#	test -f $(LIBFT_DIR)libft.a || make re -C $(LIBFT_DIR)
#	# gcc -c $(FLAG) $(FILES)
#	# gcc $(FLAG) $(OBJ) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)#	
#	rm $(OBJ)

all: $(OUT_NAME)

$(OUT_NAME):
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)

re:
	rm $(OUT_NAME) 
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)
	
libup:
	make rebonus -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -o $(OUT_NAME)
	
.PHONY:			all libup