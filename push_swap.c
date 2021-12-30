/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/30 10:40:35 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **args)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	ft_set_indexes(stack_a, ft_lstsize(*stack_a));
	return 1;
}
