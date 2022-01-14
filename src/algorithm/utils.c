/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:06:43 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 22:57:08 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	small_sorted(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(lst);
	while (lst->next)
	{
		if (((t_number *)(lst)->content)->index <
				((t_number *)(lst)->next->content)->index)
			i++;
		lst = lst->next;
	}
	return ((i + 1) == j);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	while (((t_number *)(*stack_a)->content)->index != 0)
	{
		if (((t_number *)(*stack_a)->content)->index == 0)
			rotate_a(stack_a);
		else
			rotate_a_rv(stack_a);
	}
	push_to_b(stack_a, stack_b);
	while (((t_number *)(*stack_a)->content)->index != 1)
	{
		if (((t_number *)(*stack_a)->next->content)->index == 1)
			rotate_a(stack_a);
		else
			rotate_a_rv(stack_a);
	}
	push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	while (((t_number *)(*stack_a)->content)->index != 0)
	{
		if (((t_number *)(*stack_a)->content)->index == 0)
			rotate_a(stack_a);
		else
			rotate_a_rv(stack_a);
	}
	push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	push_to_a(stack_a, stack_b);
}

void	sort_3(t_list **stack_a)
{
	while (!small_sorted(*stack_a))
	{
		if (((t_number *)(*stack_a)->content)->index >
				((t_number *)(*stack_a)->next->content)->index)
			swap_a(stack_a);
		else
			rotate_a_rv(stack_a);
	}
}
