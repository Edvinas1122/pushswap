/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:30:45 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 01:37:08 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	functions to check errors 
*/

int		ft_unused_check(int *arr, int num, int max)
{
	int	i;

	i = 0;
	while (arr[i] && i < max)
	{
		if (arr[i] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		valid_num_check(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		confirm_add(char *num, t_list *stack_a, int *num_int)
{
	if (valid_num_check(num))
	{
		num_int = ft_calloc(1, sizeof(int));
		num_int[0] = ft_atoi(num);
		ft_lstadd_back(&stack_a, ft_lstnew(num_int));
		
	}
	else
		return (0);
	return (ft_unused_check(arr, arr[i], i));
}