/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:07:25 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/03 14:19:21 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_number	*ft_replace_int(void *num)
{
	static int	i;
	t_number	*nums;

	nums = malloc(sizeof(t_number));
	nums->origin_num = *(int *)num;
	ft_putnbr_fd(nums->origin_num, 1);
	nums->index = i;
	i++;
	free(num);
	return (nums);
}

void	ft_set_index(t_list *list_address,int *buf)
{
	t_list	*tmp_lowest;
	int		*tmp_p;
	int		i;

	i = 0;
	while (list_address->next != 0 && buf[i] == 1)
	{
		list_address = list_address->next;
		i++;
	}
	tmp_p = list_address->content;
	tmp_lowest = list_address;
	buf[i] = 1;
	while (list_address->next != 0)
	{
		list_address = list_address->next;
		if (buf[i] != 1)
		{
			if (*tmp_p > *(int *)(list_address->content))
			{
				tmp_p = list_address->content;
				tmp_lowest = list_address;
				buf[i] = 1;
			}
		}
		i++;
	}
	tmp_lowest->content = ft_replace_int(tmp_lowest->content);
}

void	ft_set_indexes(t_list **list, int size)
{
	int	buf[size + 1];
	int	i;

	i = size;
	while (i > -1)
	{
		ft_bzero(&buf[i], sizeof(int));
		i--;
	}
	while (size > 0)
	{
		ft_set_index(*list, buf);
		size--;
	}
}
