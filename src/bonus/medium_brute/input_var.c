/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:08:41 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/12 21:12:19 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

/*
	Checks for errors and returns list structure as **stack_a.
	input_handler itterates trough argv (in line 47) and adds number to list 
	if string is valid number. Program is terminated if number invalid.
*/

void	ft_check_accend(t_list	**stack_a)
{
	t_list	*lst;
	void	*int_address;
	void	*int_address2;	
	int		comp;
	int		comp2;
	int		cond;

	cond = 0;
	lst = *stack_a;
	int_address = lst->content;
	comp = *(int *)int_address;
	while (lst->next != 0)
	{
		lst = lst -> next;
		int_address2 = lst->content;
		comp2 = *(int *)int_address2;
		if (comp2 < comp)
			cond = 1;
		int_address = lst->content;
		comp = *(int *)int_address;
	}
	if (!cond)
		exit (0);
}

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
	t_list	**stack_a;
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
	ft_check_accend(stack_a);
	return(stack_a);
}