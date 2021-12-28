/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/28 01:54:18 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **args)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
	swap_a(stack_a);
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr);
	push_to_b(stack_a, stack_b);
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
	push_to_a(stack_a, stack_b);
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
	rotate_a(stack_a);
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
	return 1;
}
