/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:57:23 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 23:50:32 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Pushes elements into lists
*/

void	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	**tmp2;

	tmp = *stack_from;
	ft_lstadd_front(stack_to, tmp);
	*tmp2 = *stack_from->next;
	ft_lstdelone(*stack_from);
	stack_from = tmp2;
}