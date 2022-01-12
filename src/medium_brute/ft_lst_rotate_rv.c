/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rotate_rv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:20:14 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/12 00:49:58 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
*	Pushes all elements to bottom of both stacks
*/
void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
}

void	rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*list_address;

	list_address = *list;
	tmp = *list;
	*list = list_address->next;
	while (list_address->next != NULL)
	{
		list_address = list_address->next;
	}
	list_address->next = tmp;
	tmp->next = NULL;
}