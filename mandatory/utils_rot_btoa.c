#include "push_swap.h"

int	ft_rarb_a(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = ft_find_place_a(a->top, c);
	if (i < ft_find_index(b->top, c))
		i = ft_find_index(b->top, c);
	return (i);
}

int	ft_rrarrb_a(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a->top, c))
		i = ft_lstsize(a->top) - ft_find_place_a(a->top, c);
	if ((i < (ft_lstsize(b->top) - ft_find_index(b->top, c))) && ft_find_index(b->top, c))
		i = ft_lstsize(b->top) - ft_find_index(b->top, c);
	return (i);
}

int	ft_rarrb_a(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b->top, c))
		i = ft_lstsize(b->top) - ft_find_index(b->top, c);
	i = ft_find_place_a(a->top, c) + i;
	return (i);
}

int	ft_rrarb_a(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a->top, c))
		i = ft_lstsize(a->top) - ft_find_place_a(a->top, c);
	i = ft_find_index(b->top, c) + i;
	return (i);
}