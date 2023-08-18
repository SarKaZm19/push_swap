#include "push_swap.h"

void	ft_sort_three(t_pile *a)
{
	if (ft_min(a->top) == a->top->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(a->top) == a->top->nbr)
	{
		ft_ra(a, 0);
		if (!ft_issorted(a->top))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(a->top, ft_max(a->top)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

void	ft_sort_b_max_3(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(a->top) > 3 && !ft_issorted(a->top))
	{
		tmp = a->top;
		i = find_best_rotation_atob(a, b);
		while (i >= 0)
		{
			if (i == ft_rarb(a, b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarrb(a, b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rarrb(a, b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarb(a, b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
	//fprintf(stderr, "i = %d, stack->nbr = %d\n", i, tmp->nbr);
}

t_pile	*ft_sort_b(t_pile *a, t_pile *b)
{
	if (a->actual_len > 3 && !ft_issorted(a->top))
		ft_pb(a, b, 0);
	if (a->actual_len > 3 && !ft_issorted(a->top))
		ft_pb(a, b, 0);
	if (ft_lstsize(a->top) > 3 && !ft_issorted(a->top))
		ft_sort_b_max_3(a, b);
	if (!ft_issorted(a->top))
		ft_sort_three(a);
	return (b);
}

t_pile	*ft_sort_a(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	while (b->top)
	{
		tmp = b->top;
		i = find_best_rotation_btoa(a, b);
		while (i >= 0)
		{
			if (i == ft_rarb_a(a, b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'b');
			else if (i == ft_rarrb_a(a, b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_rrarrb_a(a, b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_rrarb_a(a, b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

void make_biggest_to_top(t_pile *b)
{
	int biggest;
	int	pos;
	int	b_size;
	int nb_rot;

	biggest = ft_max(b->top);
	pos = ft_find_index(b->top, biggest);
	b_size = ft_lstsize(b->top);
	fprintf(stderr, "b_size = %d, pos = %d, max_low = %d, max_up = %d\n", b_size, pos, (b_size / 10) * 3, (b_size / 10) * 8);
	/* if (pos > ((b_size / 10) * 3) && pos < ((b_size / 10) * 8))
		return ; */
	if (pos <= b_size / 2)
	{
		nb_rot = pos;
		while (nb_rot-- > 0)
			ft_rb(b, 0);
	}	 
	else
	{
		nb_rot = b_size - pos;
		while (nb_rot-- > 0)
			ft_rrb(b, 0);
	}
}


void	push_swap(t_pile *a, t_pile *b)
{
	size_t	i;

	b->top = NULL;
	if (a->full_len == 2)
		ft_sa(a, 0);
	else if (a->full_len == 3)
		ft_sort_three(a);
	else
	{
		b = ft_sort_b(a, b);
		make_biggest_to_top(b);
		a = ft_sort_a(a, b);
		i = ft_find_index(a->top, ft_min(a->top));
		if (i < ft_lstsize(a->top) - i)
		{
			while (a->top->nbr != ft_min(a->top))
				ft_ra(a, 0);
		}
		else
		{
			while (a->top->nbr != ft_min(a->top))
				ft_rra(a, 0);
		}	
	}
}
