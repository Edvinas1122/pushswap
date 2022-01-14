/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 23:13:32 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_end(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, ft_delete);
	free(stack_a);
	free(stack_b);
}

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
		ft_radix(stack_a, stack_b, num - 1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = input_handler(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_list *));
	ft_set_indexes(stack_a, argc - 1);
	engine(stack_a, stack_b, argc - 1);
	ft_stack_end(stack_a, stack_b);
}
