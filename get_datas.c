#include "push_swap.h"

static int	check_duplicates(char **datas, int st)
{
	int	i;

	i = st + 1;
	while (datas[i])
	{
		if (!ft_strcmp(datas[st], datas[i]))
			break ;
		i++;
	}
	if (!datas[i])
		return (1);
	return (0);
}

static t_stack	*check_args(char **datas)
{
	int	i;
	int	nb;
	int	error_flag;
	t_stack	*a;
	t_stack *new_node;

	a = NULL;
	error_flag = 0;
	i = -1;
	while (datas[++i])
	{
		if (!check_duplicates(datas, i))
			return (NULL);
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
