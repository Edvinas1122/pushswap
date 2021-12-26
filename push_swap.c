/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:47 by emomkus           #+#    #+#             */
/*   Updated: 2021/12/21 01:00:29 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argv, char **args)
{
	int		*arr;
	int		i;

	i = 0;
	arr = input_handler(argv, args);
	while(arr[i]) // debug input
	{
		ft_putnbr_fd(arr[i], 1);
		write(1, "\n", 1);
		i++;
	}
	
	return 1;
}