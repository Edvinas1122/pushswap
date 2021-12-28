# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2021/12/28 03:29:05 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Update bellow -----------------------------------------------#

MAIN_FILE = push_swap.c
MEDIUM_FILES = confirm_add.c input_var.c ft_lst_swap.c ft_lst_push.c \
			ft_lst_rotate.c ft_lst_rotate_rv.c
MEDIUM_FILES_DIR = src/medium/
MONITOR_FILES = print_feature_bonus.c
OBJ = push_swap.o confirm_add.o	input_var.o
LIBFT_FILES = libft.h libft.a 
LIBFT_DIR = libft/
FLAG = -Wall -Wextra -Werror
HEADER = push_swap.h

#---- Update above ------------------------------------------------#

MEDIUM = $(addprefix $(MEDIUM_FILES_DIR),$(MEDIUM_FILES))#	medium files #
FILES = $(MAIN_FILE) $(MEDIUM) $(MONITOR_FILES)#				ALL FILES #
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES)) #			LIBFT library #
OUT_NAME = push_swap # 								program name output #

all: $(OUT_NAME)

$(OUT_NAME):
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)

re:
	rm $(OUT_NAME) 
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)
	
libup:
	make rebonus -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)
	
.PHONY:			all re libup