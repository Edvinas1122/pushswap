/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:08:41 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 21:45:36 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete(void *num)
{
	free(num);
}

void	ft_terminate(t_list **stack_a)
{
	if (*stack_a)
		ft_lstclear(stack_a, ft_delete);
	free(stack_a);
	write(1, "Error", 5);
	exit (0);
}

t_list	**input_handler(int argc, char **argv)
{
	t_list	**stack_a = NULL;
	int		i;

	i = 1;
	if (argc <= 1)
	{
		write(1, "Error", 5);
		exit (0);
	}
	stack_a = malloc(sizeof(t_list *));
	while (argv[i])
	{
		if (ft_confirm_add(argv[i], stack_a))
			i++;
		else
			ft_terminate(stack_a);
	}
	return(stack_a);
}