/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:08:41 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 01:35:11 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_terminate(int *arr)
{
	free(arr);
	write(1, "Error", 5);
	exit (0);
}

int		*input_handler(int argc, char **argv)
{
	t_list	*stack_a;
	int 	*num_int;
	int		i;

	i = 1;
	if (argc <= 1) // count
	{
		write(1, "Error", 5);
		exit (0);
	}
	// arr = ft_calloc((argc - 1), sizeof(int)); // alocating array of ints
	while (argv[i])
	{
		if (confirm_add(argv[i], stack_a, num_int))
			i++;
		else
			ft_terminate(arr);
	}
	return(arr);
}