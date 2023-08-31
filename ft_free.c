#include "push_swap.h"

void	ft_free_all(t_pile *a, t_pile *b)
{
	ft_free_stack(&(a->top));
	ft_free_stack(&(b->top));
	free(a);
	free(b);
	exit(1);
}

void	ft_free_tab(char **str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->nbr = 0;
		free(*a);
		(*a) = tmp;
	}
}