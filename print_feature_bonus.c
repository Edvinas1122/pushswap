/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_feature_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:20:02 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/11 18:48:48 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_num(void *content)
{
	t_number	*num;
	int i;

	num = content;
	i = num->index;
	ft_putnbr_fd(i, 1);
	write(1, " ", 1);
}

/*
*	Prints into terminal integer pointed by void pointer
*/
void	ft_putnbr_tr2(void *content)
{
	int	*num;

	num = content;
	ft_putnbr_fd(num[0], 1);
}

/*
*	Prints into terminal integer pointed by void pointer with newline
*/
void	ft_putnbr_tr(void *content)
{
	int	*num;

	num = content;
	ft_putnbr_fd(num[0], 1);
	write(1, "\n", 1);
}

void	ft_b_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst->next != 0)
	{
		write(1, "     ", 2);
		(*f)(lst->content);
		lst = lst -> next;
	}
	write(1, "     ", 2);
	(*f)(lst->content);
}

/*
*	Lists both stacks
*/
void	ft_ab_lstiter(t_list *lst, t_list *lst2, void (*f)(void *))
{
	int		stack_a;
	int		stack_b;

	stack_a = ft_lstsize(lst);
	stack_b = ft_lstsize(lst2);
	if (stack_b == 0)
	{
		write(1, "\n", 1);
		ft_lstiter(lst, ft_putnbr_tr);
		write(1, "----\n", 5);
		return;
	}
	if (stack_a == 0)
	{
		write(1, "\n", 1);
		ft_b_lstiter(lst2, ft_putnbr_tr);
		write(1, "----\n", 5);
		return;
	}
	write(1, "\n", 1);
	while (lst->next != 0 || lst2->next != 0)
	{
		if (stack_a > stack_b)
		{
			(*f)(lst->content);
			write(1, "\n", 1);
			lst = lst -> next;
			stack_a--;
		}
		else if (stack_a < stack_b)
		{
			write(1, "         ", 2);
			(*f)(lst2->content);
			write(1, "\n", 1);
			lst2 = lst2 -> next;
			stack_b--;
		}
		else if (stack_a == stack_b)
		{
			(*f)(lst->content);
			lst = lst -> next;
			write(1, "    ", 1);
			(*f)(lst2->content);
			lst2 = lst2 -> next;
			write(1, "\n", 1);
		}
	}
	(*f)(lst->content);
	write(1, "         ", 1);
	(*f)(lst2->content);
	write(1, "\n----\n", 6);
}

void	ft_simple_lister(t_list *lst, void (*f)(void *))
{
	while (lst->next != 0)
	{
		(*f)(lst->content);
		lst = lst -> next;
	}
	(*f)(lst->content);
	write(1, "\n", 1);
}
