/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/11 23:03:54 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int		*val_0;
	int		*val_1;
	int		*val_2;

	val_0 = (*stack_a)->content;
	val_1 = (*stack_a)->next->content;
	val_2 = (*stack_a)->next->next->content;
	if ((*val_2 >= *val_0) && (*val_2 >= *val_1) && (*val_0 >= *val_1))
		swap_a(stack_a);
	else if ((*val_0 >= *val_1) && (*val_0 >= *val_2) && (*val_1 >= *val_2))
	{
		swap_a(stack_a);
		rotate_a_rv(stack_a);
	}
	else if ((*val_0 >= *val_1) && (*val_0 >= *val_2) && (*val_2 >= *val_1))
		rotate_a(stack_a);
	else if ((*val_1 >= *val_0) && (*val_1 >= *val_2) && (*val_2 >= *val_0))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*val_1 >= *val_0) && (*val_1 >= *val_2) && (*val_0 >= *val_2))
		rotate_a_rv(stack_a);
}

void	sort_2_3(t_list **stack_a, int num)
{
	if (num == 2)
		swap_a(stack_a);
	else
		sort_3(stack_a);
}

void	engine(t_list **stack_a, t_list **stack_b, int num)
{
	if (num <= 3)
		sort_2_3(stack_a, num);
	free(stack_b);
	else if (num <= 5)
		sort_4_5(stack_a, stack_b, num);
	// else
	// 	the_sorter(stack_a, stack_b, num);
}

int		main(int argv, char **args)
{
	
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	ft_set_indexes(stack_a, ft_lstsize(*stack_a));
	ft_simple_lister(*stack_a, ft_putnbr_num); // displaying indexes
	engine(stack_a, stack_b, argv - 1);

	return 1;
}
