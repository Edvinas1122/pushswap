# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2022/01/05 12:00:29 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Update bellow -----------------------------------------------#

MAIN_FILE = push_swap.c
SORT_FILE = sort_read.c
MEDIUM_FILES = confirm_add.c input_var.c ft_lst_swap.c ft_lst_push.c \
			ft_lst_rotate.c ft_lst_rotate_rv.c
MEDIUM_FILES_DIR = src/medium/
ALG_FILES = set_index.c
ALG_FILES_DIR = src/algorithm/
MONITOR_FILES = print_feature_bonus.c
OBJ = push_swap.o confirm_add.o	input_var.o
LIBFT_FILES = libft.h libft.a 
LIBFT_DIR = libft/
FLAG = -Wall -Wextra -Werror
HEADER = push_swap.h

#---- Update above ------------------------------------------------#

MEDIUM = $(addprefix $(MEDIUM_FILES_DIR),$(MEDIUM_FILES))#	medium files #
ALG = $(addprefix $(ALG_FILES_DIR),$(ALG_FILES))
FILES = $(MAIN_FILE) $(MEDIUM) $(ALG) $(MONITOR_FILES)#		ALL FILES #
FILES2 = $(SORT_FILE) $(MEDIUM) $(MONITOR_FILES)#				ALL FILES #
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES)) #			LIBFT library #
OUT_NAME = push_swap # 								program name output #
OUT_NAME_2 = stack_sort_game

all: $(OUT_NAME)

$(OUT_NAME):
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)

re:
	rm -f $(OUT_NAME) 
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)
	
libup:
	make rebonus -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	gcc -g $(FLAG) $(FILES) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME)

sort:
	test -f $(OUT_NAME_2) || rm -f $(OUT_NAME_2)
	test -f $(LIBFT_DIR)libft.a || make rebonus -C $(LIBFT_DIR)
	gcc $(FLAG) $(FILES2) -I $(HEADER) -I $(LIBFT) -o $(OUT_NAME_2)

	
.PHONY:			all re libup