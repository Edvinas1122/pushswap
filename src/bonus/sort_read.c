/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:51:07 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/12 21:11:45 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		protect_cases(char *buf, t_list **stack_a, t_list **stack_b)
{
	int len_a = ft_lstsize(*stack_a);
	int len_b = ft_lstsize(*stack_b);

	if (len_a < 2)
	{
		if(!ft_strncmp(buf, "RRA", 3) || !ft_strncmp(buf, "RRR", 3) ||
			 !ft_strncmp(buf, "SA", 2) || !ft_strncmp(buf, "SS", 2) || 
			 !ft_strncmp(buf, "RA", 2) || !ft_strncmp(buf, "RR\0", 3))
		{
			write(1, "Not valid move :|", 18);
			return (0);
		}
		if(len_a == 0 && !ft_strncmp(buf, "PB", 2))
		{
			write(1, "Not valid move :|", 18);
			return (0);
		}
	}
	if (len_b < 2)
	{
		if(!ft_strncmp(buf, "RRB", 3) || !ft_strncmp(buf, "RRR", 3) ||
			 !ft_strncmp(buf, "SB", 2) || !ft_strncmp(buf, "SS", 2) || 
			 !ft_strncmp(buf, "RB", 2) || !ft_strncmp(buf, "RR\0", 3))
		{
			write(1, "Not valid move :|", 18);
			return (0);
		}
		if(len_b == 0 && !ft_strncmp(buf, "PA", 2))
		{
			write(1, "Not valid move :|", 18);
			return (0);
		}
	}
	return 1;
}

void	swap_cases(char *buf, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(buf, "RRA", 3))
		rotate_a_rv(stack_a);
	else if (!ft_strncmp(buf, "RRB", 3))
		rotate_b_rv(stack_b);
	else if (!ft_strncmp(buf, "RRR", 3))
		rotate_ab_rv(stack_a, stack_b);
	else if (!ft_strncmp(buf, "SA", 2))
		swap_a(stack_a);
	else if (!ft_strncmp(buf, "SB", 2))
		swap_b(stack_b);
	else if (!ft_strncmp(buf, "SS", 2))
		swap_ab(stack_a, stack_b);
	else if (!ft_strncmp(buf, "PA", 2))
		push_to_a(stack_a, stack_b);
	else if (!ft_strncmp(buf, "PB", 2))
		push_to_b(stack_a, stack_b);
	else if (!ft_strncmp(buf, "RA", 2))
		rotate_a(stack_a);
	else if (!ft_strncmp(buf, "RB", 2))
		rotate_b(stack_b);
	else if (!ft_strncmp(buf, "RR", 2))
		rotate_ab(stack_a, stack_b);
	else
		write(1, "wrong input, use SA, SB, SS, PA, PB, RA, RR, RRA, RRB, RRR", 59);

}

int		check_accend(t_list	**stack_a, t_list **stack_b)
{
	t_list	*lst;
	void	*int_address;
	void	*int_address2;	
	int		comp;
	int		comp2;
	int		cond;

	cond = 0;
	lst = *stack_a;
	if (ft_lstsize(*stack_b))
		return (1);
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
		write(1, "\nArray sorted\n", 14);
	return (cond);
}

int		main(int argv, char **args)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	buf[4];

	ft_bzero(buf, 4);
	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	write(1, "Use SA, SB, SS, PA, PB, RA, RR, RRA, RRB, RRR to sort\n", 55);
	while (check_accend(stack_a, stack_b))
	{
		ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
		read(1, buf, 4);
		if (protect_cases(buf, stack_a, stack_b))
			swap_cases(buf, stack_a, stack_b);
		ft_bzero(buf, 4);
	}
	ft_ab_lstiter(*stack_a, *stack_b, ft_putnbr_tr2);
	return 1;
}