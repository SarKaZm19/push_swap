#include "push_swap_bonus.h"

void	check_duplicates(t_stack **lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->nbr == tmp->nbr)
				return (ft_free_stack(lst));
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

static t_stack	*get_nbs(char **data_set)
{
	t_stack	*a;
	t_stack *new_node;
	size_t	i;
	int		nb;
	int		error_flag;

	a = NULL;
	error_flag = 0;
	i = -1;
	while (data_set[++i])
	{
		nb = ft_atoi2(data_set[i], &error_flag);
		if (error_flag == -1)
			return (ft_putendl_fd("datas error", 2), NULL);
		new_node = ft_stack_new(nb);
		if (!new_node)
			return (ft_putendl_fd("malloc error", 2), NULL);
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
		usage_error();
	else if (ac == 2)
	{
		data_set = ft_split(av[1], ' ');
		if (!data_set)
			ft_malloc_error("ft_split: ");
		a = get_nbs(data_set);
		ft_free_tab(data_set);
	}
	else
		a = get_nbs(av + 1);
	return (a);
}
