#include "push_swap_bonus.h"

void	ft_free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		(*s)->nbr = 0;
		free(*s);
		(*s) = tmp;
	}
}

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

void	gnl_loop(t_stack **a, t_stack **b)
{
	char	*line;
	int		exec_error;

	line = get_next_line(0);
	while (line)
	{
		exec_error = exec_line(line, a, b);
		free(line);
		if (exec_error == 1)
		{
			ft_free_stack(&a);
			ft_free_stack(&b);
			exit(EXIT_FAILURE);
		}
		line = get_next_line(0);
	}
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = get_av(ac, av);
	if (!a)
		return (ft_free_stack(&a), 1);
	check_duplicates(&a)
	b = NULL;
	gnl_loop(&a, &b);
	if (!ft_issorted(a) || b)
		ft_putendl_fd("KO", 1);
	ft_putendl_fd("OK", 1;)
	ft_free_stack(&a);
}
