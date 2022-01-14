/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:03:50 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 22:46:00 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	bitlength(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix(t_list **stack_a, t_list **stack_b, int size)
{
	int	max_bits;
	int	i;
	int	cur;
	int	j;

	max_bits = bitlength(size);
	i = 0;
	while (max_bits != 0)
	{
		j = 0;
		while (j <= size)
		{
			cur = ((t_number *)(*stack_a)->content)->index;
			if (((cur >> i) & 1))
				rotate_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
			j++;
		}
		i++;
		while (*stack_b)
			push_to_a(stack_a, stack_b);
		max_bits--;
	}
}
