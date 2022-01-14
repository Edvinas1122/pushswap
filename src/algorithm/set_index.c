/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:07:25 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/14 22:55:49 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_number	*ft_replace_int(void *num)
{
	static int	i;
	t_number	*nums;

	nums = malloc(sizeof(t_number));
	nums->origin_num = *(int *)num;
	nums->index = i;
	i++;
	free(num);
	return (nums);
}

int	return_first_pointer(t_list **tmp_lowest, t_list **list_address,
						int i, int *buf)
{
	t_list	*lowest;
	t_list	*address;

	lowest = *tmp_lowest;
	address = *list_address;
	while (!lowest)
	{
		if (buf[i] == 0)
			lowest = address;
		else
		{
			address = address->next;
			i++;
		}
	}
	*tmp_lowest = lowest;
	*list_address = address;
	return (i);
}

int	ft_set_index(t_list *list_address, int *buf)
{
	t_list	*tmp_lowest;
	int		i;
	int		x;

	tmp_lowest = NULL;
	i = return_first_pointer(&tmp_lowest, &list_address, 0, buf);
	x = i;
	while (list_address->next != 0)
	{
		list_address = list_address->next;
		if (buf[i + 1] != 1)
		{
			if (*(int *)tmp_lowest->content > *(int *)(list_address->content))
			{
				tmp_lowest = list_address;
				x = i + 1;
			}
		}
		i++;
	}
	tmp_lowest->content = ft_replace_int(tmp_lowest->content);
	return (x);
}

void	ft_set_indexes(t_list **list, int size)
{
	int	*buf;

	buf = ft_calloc(size, sizeof(int));
	while (size > 0)
	{
		buf[ft_set_index(*list, buf)] = 1;
		size--;
	}
	free(buf);
}
