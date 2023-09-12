/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:31:46 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 19:43:39 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *datas, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i;
		while (++j < len)
			if (datas[i] == datas[j])
				return (1);
		i++;
	}
	return (0);
}

static t_stack	*check_args(char **datas)
{
	int		i;
	int		nb;
	int		error_flag;
	t_stack	*a;
	t_stack	*new_node;

	a = NULL;
	error_flag = 0;
	i = -1;
	while (datas[++i])
	{
		if (!*datas[i])
			return (ft_free_stack(&a), NULL);
		nb = ft_atoi2(datas[i], &error_flag);
		if (error_flag == -1)
			return (ft_free_stack(&a), NULL);
		new_node = ft_stack_new(nb);
		if (!new_node)
			return (ft_free_stack(&a), NULL);
		ft_add_back(&a, new_node);
	}
	return (a);
}

t_stack	*get_av(int ac, char **av)
{
	char	**data_set;
	t_stack	*a;

	a = NULL;
	if (ac < 2)
		return (NULL);
	if (ac == 2)
	{
		data_set = ft_split(av[1], ' ');
		if (!data_set)
			return (NULL);
		a = check_args(data_set);
		ft_free_tab(data_set);
	}
	else
		a = check_args(av + 1);
	return (a);
}
