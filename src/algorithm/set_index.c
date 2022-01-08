/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:07:25 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/06 15:05:17 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_number	*ft_replace_int(void *num)
{
	static int	i;
	i = 0;
	t_number	*nums;

	nums = malloc(sizeof(t_number));
	nums->origin_num = *(int *)num;
	ft_putnbr_fd(nums->origin_num, 1);
	write(1,"\n",1);
	nums->index = i;
	i++;
	free(num);
	return (nums);
}

//bzero before set index? 

void	ft_set_indexes(t_list **list, int size)
{
	int	buf[size];
	int	i;
	int defsize;

	i = size;
	defsize = size;
	while (i > -1)
	{
		ft_bzero(&buf[i], sizeof(int));
		i--;
	}
	while (size > 0)
	{
		//buf[ft_set_index(*list, buf)] = 1;
		buf[ft_set_index(*list, buf, defsize)] = 1;
		size--;
	}
}

//always breaks because always first element as lowest. if first not lowest then breaks.
//pull out if statement 46 - 56