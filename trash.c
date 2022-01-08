int	ft_set_index(t_list *list_address,int *buf, int defsize)
{
	t_list	*tmp_lowest;
	int		*tmp_p;
	int		i;
	int		x;
	t_list	*first;
	//new

	x = 0;
	//new
	i = 0;
	// while (list_address->next != 0 && buf[i] == 1)
	// {
	// 	list_address = list_address->next;
	// 	i++;
	// }
	first = list_address;
	tmp_lowest = NULL;
	while(defsize)
	{
		if(buf[i] != 1)
		{
			tmp_p = list_address->content;
			tmp_lowest = list_address;
			break ;
		}
		else
			i++;
		defsize--;
		list_address = list_address->next;
	}
	//i = 0;
	list_address = first;
	//buf[i] = 1;
	while (list_address->next != 0)
	{
		list_address = list_address->next;
		if (buf[i] != 1)
		{
			if (*tmp_p > *(int *)(list_address->content))
			{
				tmp_p = list_address->content;
				tmp_lowest = list_address;
				//buf[i] = 1;
				x = i;
				//new
			}
		}
		i++;
	}
	//buf[x] = 1;
	//new
	tmp_lowest->content = ft_replace_int(tmp_lowest->content);
	return (x);
}