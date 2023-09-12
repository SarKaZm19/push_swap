/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:27 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:12:00 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_issorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->nbr < lst->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	add_op(t_list **ops, char *operation)
{
	int			i;
	t_list		*new_op;
	static char	*all_ops[11] = {"ra\n", "rra\n", "sa\n", "pa\n", "rb\n",
		"rrb\n", "sb\n", "pb\n", "rr\n", "rrr\n", "ss\n"};

	new_op = NULL;
	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(operation, all_ops[i]))
			break ;
		i++;
	}
	if (i == 11)
		return (1);
	new_op = ft_lstnew(operation);
	if (!new_op)
		return (1);
	ft_lstadd_back(ops, new_op);
	return (0);
}

static t_list	*gnl_loop(void)
{
	t_list	*ops;
	char	*line;
	int		op_error;
	int		read_error;

	ops = NULL;
	read_error = 0;
	while (1)
	{
		line = get_next_line(0, &read_error);
		if (!line && !read_error)
			return (ops);
		if (!read_error)
			op_error = add_op(&ops, line);
		if (op_error || read_error)
		{
			ft_free_operations(&ops);
			prog_error();
			exit(EXIT_FAILURE);
		}
	}
	return (ops);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*operations;
	t_list	*tmp;

	a = get_av(ac, av);
	if (!a)
		return (ft_free_stack(&a), prog_error(), 1);
	b = NULL;
	operations = gnl_loop();
	tmp = operations;
	while (tmp && tmp->content)
	{
		exec_op(tmp->content, &a, &b);
		tmp = tmp->next;
	}
	if (!ft_issorted(a) || b)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	ft_free_operations(&operations);
	ft_free_stack(&a);
	return (0);
}
