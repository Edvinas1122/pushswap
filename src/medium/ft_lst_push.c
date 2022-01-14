/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:57:23 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/28 02:20:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
*	Pushes top b stack element into top a stack
*/
void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "PA\n", 3);
}

/*
*	Pushes top a stack element into b stack
*/
void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "PB\n", 3);
}

void	push(t_list **from, t_list **to)
{
	t_list	*from_addr;
	t_list	*tmp;

	tmp = *to;
	*to = *from;
	from_addr = *from;
	*from = from_addr->next;
	from_addr->next = tmp;
}
