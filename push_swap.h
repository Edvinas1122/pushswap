/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:51 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 21:16:57 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct number
{
	int i;
	int index;
}number;

int		main(int argv, char **args);
void	ft_putnbr_tr(void *content);
int		ft_confirm_add(char *num, t_list **stack_a);
int		valid_num_check(char *num);
int		ft_unused_check(t_list *lst, int num, int *address);
t_list	**input_handler(int argc, char **argv);
void	ft_delete(void *num);
void	ft_terminate(t_list **stack_a);

#endif