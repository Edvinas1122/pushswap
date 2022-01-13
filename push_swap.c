/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/13 16:33:13 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	engine(t_list **stack_a, t_list **stack_b, int num)
{
	if (num == 2)
		swap_a(stack_a);
	else if (num == 3)
		sort_3(stack_a);
	else if (num == 4)
		sort_4(stack_a, stack_b);
	else if (num == 5)
		sort_5(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b, num);
}

int		main(int argv, char **args)
{
	
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	ft_set_indexes(stack_a, ft_lstsize(*stack_a));
	// ft_simple_lister(*stack_a, ft_putnbr_num); // displaying indexes
	engine(stack_a, stack_b, argv - 1);

	return 1;
}
