#include "push_swap.h"

int	find_best_rotation_btoa(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b->top;
	i = ft_rrarrb_a(a, b, b->top->nbr);
	while (tmp)
	{
		if (i > ft_rarb_a(a, b, tmp->nbr))
			i = ft_rarb_a(a, b, tmp->nbr);
		if (i > ft_rrarrb_a(a, b, tmp->nbr))
			i = ft_rrarrb_a(a, b, tmp->nbr);
		if (i > ft_rarrb_a(a, b, tmp->nbr))
			i = ft_rarrb_a(a, b, tmp->nbr);
		if (i > ft_rrarb_a(a, b, tmp->nbr))
			i = ft_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	find_best_rotation_atob(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a->top;
	i = ft_rrarrb(a, b, a->top->nbr);
	while (tmp)
	{
		if (i != 0 && i > ft_rarb(a, b, tmp->nbr))
			i = ft_rarb(a, b, tmp->nbr);
		if (i != 0 && i > ft_rrarrb(a, b, tmp->nbr))
			i = ft_rrarrb(a, b, tmp->nbr);
		if (i != 0 && i > ft_rarrb(a, b, tmp->nbr))
			i = ft_rarrb(a, b, tmp->nbr);
		if (i != 0 && i > ft_rrarb(a, b, tmp->nbr))
			i = ft_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}