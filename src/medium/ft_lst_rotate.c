/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:23:24 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 22:58:54 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
*	Pushes all elements to bottom of both stacks
*/
void	rotate_ab_rv(t_list **stack_a, t_list **stack_b)
{
	rotate_rv(stack_a);
	rotate_rv(stack_b);
	write(1, "RRR\n", 4);
}

void	rotate_b_rv(t_list **stack_b)
{
	rotate_rv(stack_b);
	write(1, "RRB\n", 4);
}

void	rotate_a_rv(t_list **stack_a)
{
	rotate_rv(stack_a);
	write(1, "RRA\n", 4);
}

void	rotate_rv(t_list **list)
{
	t_list	*i;
	t_list	*tmp;
	t_list	*list_address;

	list_address = *list;
	tmp = *list;
	while (list_address->next != NULL)
	{
		i = list_address;
		list_address = list_address->next;
		*list = list_address;
	}
	i->next = NULL;
	list_address->next = tmp;
}
