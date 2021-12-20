/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:51 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/20 23:46:55 by emomkus          ###   ########.fr       */
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
int		confirm_add(char *num, int *arr, int i);
int		valid_num_check(char *num);
int		ft_unused_check(int *arr, int num, int max);
int		*input_handler(int argc, char **argv);
void	ft_terminate(int *arr);

#endif