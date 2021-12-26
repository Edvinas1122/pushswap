/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/26 23:56:12 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_tr2(void *content)
{
	int	*num;

	num = content;
	ft_putnbr_fd(num[0], 1);
}

void	ft_putnbr_tr(void *content)
{
	int	*num;

	num = content;
	ft_putnbr_fd(num[0], 1);
	write(1, "\n", 1);
}

void	ft_ab_lstiter(t_list *lst, t_list *lst2, void (*f)(void *))
{
	int	stack_a;
	int	stack_b;

	stack_a = ft_lstsize(lst);
	stack_b = ft_lstsize(lst2);
	while (lst->next != 0 && lst2->next != 0)
	{
		if (stack_a > stack_b)
		{
			(*f)(lst->content);
			lst = lst -> next;
			stack_a--;
		}
		else if (stack_a < stack_b)
		{
			(*f)(lst2->content);
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
	write(1, "    ", 1);
	(*f)(lst2->content);
	write(1, "\n", 1);
}

int	main(int argv, char **args)
{
	t_list	**stack_a;
	// t_list	**stack_b;

	stack_a = input_handler(argv, args);
	// stack_b = malloc(sizeof(t_list *));
	ft_lstiter(*stack_a, ft_putnbr_tr);
	swap_a(stack_a);
	ft_lstiter(*stack_a, ft_putnbr_tr);
	// push(stack_b, stack_a);
	// ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2)
	return 1;
}
