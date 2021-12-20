/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:30:45 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/20 23:50:33 by emomkus          ###   ########.fr       */
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

int		confirm_add(char *num, int *arr, int i)
{
	if (valid_num_check(num))
		arr[i] = ft_atoi(num);
	else
		return (0);
	return (ft_unused_check(arr, arr[i], i));
}