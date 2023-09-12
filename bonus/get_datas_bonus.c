/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:25 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:10:05 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*mem;

	tmp = a;
	while (tmp)
	{
		mem = tmp->next;
		while (mem)
		{
			if (tmp->nbr == mem->nbr)
				return (1);
			mem = mem->next;
		}
		tmp = tmp->next;
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
	if (check_duplicates(a))
		return (ft_free_stack(&a), NULL);
	return (a);
}

t_stack	*get_av(int ac, char **av)
{
	char	**data_set;
	t_stack	*a;

	a = NULL;
	if (ac < 2)
		exit(0);
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
