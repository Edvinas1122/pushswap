/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 21:10:11 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_tr(void *content)
{
	int	*num;

	num = content;
	ft_putnbr_fd(num[0], 1);
	write(1, "\n", 1);
}

int	main(int argv, char **args)
{
	t_list	**stack_a;

	stack_a = input_handler(argv, args);
	ft_lstiter(*stack_a, ft_putnbr_tr);
	
	return 1;
}