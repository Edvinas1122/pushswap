/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:51 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 21:32:56 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "GNL/get_next_line.h"




typedef struct s_number
{
	int origin_num;
	int index;
} t_number;

int		main(int argv, char **args);
/*Input value and error handling*/
void	ft_terminate(t_list **stack_a);
int		ft_confirm_add(char *num, t_list **stack_a);
int		valid_num_check(char *num);
int		ft_unused_check(t_list *lst, int num, int *address);
t_list	**input_handler(int argc, char **argv);
void	ft_check_accend(t_list	**stack_a);
/*ALGORITHM*/
int		bitlength(int num);
void	engine(t_list **stack_a, t_list **stack_b, int num);
void	ft_radix(t_list **a, t_list **b, int size);
/*Small sort*/
int		small_sorted(t_list *lst);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
/*set index*/
void		ft_set_indexes(t_list **list, int size);
int			ft_set_index(t_list *list_address, int *buf);
t_number	*ft_replace_int(void *num);
/*Push*/
void	push(t_list **from, t_list **to);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
/*Rotate*/
void	rotate(t_list **list);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	rotate_rv(t_list **list);
void	rotate_a_rv(t_list **stack_a);
void	rotate_b_rv(t_list **stack_b);
void	rotate_ab_rv(t_list **stack_a, t_list **stack_b);
/*Swap*/
void	swap(t_list **lst);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);
/*Print stacks*/
void	ft_putnbr_bin(void *content);
void	ft_putnbr_tr(void *content);
void	ft_putnbr_tr2(void *content);
void	ft_delete(void *num);
void	ft_ab_lstiter(t_list *lst, t_list *lst2, void (*f)(void *));
void	ft_b_lstiter(t_list *lst, void (*f)(void *));
void	ft_putnbr_tr(void *content);
void	ft_putnbr_tr2(void *content);
void	ft_simple_lister(t_list *stack_a, void (*f)(void *));
void	ft_putnbr_num(void *content);
void	ft_putnbr_tr3(void *content);
/*BONUS APP input visualizer*/
int		check_accend(t_list	**stack_a, t_list **stack_b);
void	swap_cases(char *buf, t_list **stack_a, t_list **stack_b);


#endif
