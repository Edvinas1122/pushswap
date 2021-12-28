/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:19:11 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/28 02:20:57 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
*	Swaps top elements of both stacks
*/
void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "SS\n", 3);
}

/*
*	Swaps top elements of b stack
*/
void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	write(1, "SB\n", 3);
}

/*
*	Swaps top elements of a stack
*/
void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	write(1, "SA\n", 3);
}

void	swap(t_list **lst)
{
	t_list	*top;
	t_list	*bellow;
	void	*tmp_address;

	top = *lst;
	if (top->next == NULL)
		write(1, "Swaping empty list", 18);
	else
	{
		bellow = top->next;
		tmp_address = top->content;
		top->content = bellow->content;
		bellow->content = tmp_address;
	}
}
