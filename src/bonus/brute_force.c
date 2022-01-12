/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:10:32 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/12 21:11:33 by emomkus          ###   ########.fr       */
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
			return (0);
		}
		if(len_a == 0 && !ft_strncmp(buf, "PB", 2))
		{
			return (0);
		}
	}
	if (len_b < 2)
	{
		if(!ft_strncmp(buf, "RRB", 3) || !ft_strncmp(buf, "RRR", 3) ||
			 !ft_strncmp(buf, "SB", 2) || !ft_strncmp(buf, "SS", 2) || 
			 !ft_strncmp(buf, "RB", 2) || !ft_strncmp(buf, "RR\0", 3))
		{
			return (0);
		}
		if(len_b == 0 && !ft_strncmp(buf, "PA", 2))
		{
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
}

void	swap_cases_rev(char *buf, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(buf, "RRA", 3))
		rotate_a(stack_a);
	else if (!ft_strncmp(buf, "RRB", 3))
		rotate_b(stack_b);
	else if (!ft_strncmp(buf, "RRR", 3))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strncmp(buf, "SA", 2))
		swap_a(stack_a);
	else if (!ft_strncmp(buf, "SB", 2))
		swap_b(stack_b);
	else if (!ft_strncmp(buf, "SS", 2))
		swap_ab(stack_a, stack_b);
	else if (!ft_strncmp(buf, "PA", 2))
		push_to_b(stack_a, stack_b);
	else if (!ft_strncmp(buf, "PB", 2))
		push_to_a(stack_a, stack_b);
	else if (!ft_strncmp(buf, "RA", 2))
		rotate_a_rv(stack_a);
	else if (!ft_strncmp(buf, "RB", 2))
		rotate_b_rv(stack_b);
	else if (!ft_strncmp(buf, "RR", 2))
		rotate_ab_rv(stack_a, stack_b);
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
	return (cond);
}

// int	brute_force(t_list **stack_a, t_list **stack_b, char **comands, int i, int argv)
// {
// 	// int			ct = 0;
// 	static int	arr[20];
// 	static int	check = 1;

// 	if (check != argv)
// 	{
// 		ft_bzero(arr, 4 * 20);
// 		check = argv;
// 	}
// 	while (check_accend(stack_a, stack_b) && i < argv && arr[i] < 11)
// 	{
// 		if (protect_cases(comands[arr[i]], stack_a, stack_b))
// 		{
// 			swap_cases(comands[arr[i]], stack_a, stack_b);
// 			brute_force(stack_a, stack_b, comands, i + 1, argv);
// 			if (!check_accend(stack_a, stack_b))
// 				break;
// 			swap_cases_rev(comands[arr[i]], stack_a, stack_b);
// 		}
// 		arr[i]++;
// 	}
// 	if (!check_accend(stack_a, stack_b))
// 	{
// 		write(1, comands[arr[i]], 3);
// 		write(1, " ", 1);
// 	}
// 	return (arr[i]);
// }

int	brute_force(t_list **stack_a, t_list **stack_b, char **comands, int i, int argv)
{
	int		ct = 0;

	while (check_accend(stack_a, stack_b) && i < argv && ct < 11)
	{
		if (protect_cases(comands[ct], stack_a, stack_b))
		{
			swap_cases(comands[ct], stack_a, stack_b);
			brute_force(stack_a, stack_b, comands, i + 1, argv);
			if (!check_accend(stack_a, stack_b))
				break;
			swap_cases_rev(comands[ct], stack_a, stack_b);
		}
		ct++;
	}
	if (!check_accend(stack_a, stack_b))
	{
		write(1, comands[ct], 3);
		write(1, " ", 1);
	}
	return (ct);
}

int		main(int argv, char **args)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i = 0;
	int		ct = 11;
	int		arg = 1;
	int		x;
	// int		arr[10];

    char *comands[12] = { "SA",
                    	"SB",
                        "SS",
                        "RA",
                        "RB",
	                	"RR",
                        "PA",
                        "PB",
                        "RRA",
						"RRB",
                        "RRR"
						 };

	stack_a = input_handler(argv, args);
	stack_b = ft_calloc(1, sizeof(t_list *));
	x = 0;
	while (x < 10)
	{
		ct = brute_force(stack_a, stack_b, comands, i, arg);
		if (ct != 11)
		{
			stack_a = input_handler(argv, args);
			write(1, "\n", 1);
			x++;
		}else
			arg++;
	}
	return 1;
}
