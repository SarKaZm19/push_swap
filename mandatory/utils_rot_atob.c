#include "push_swap.h"

int	ft_rarb(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = ft_find_place_b(b->top, c);
	if (i < ft_find_index(a->top, c))
		i = ft_find_index(a->top, c);
	return (i);
}

int	ft_rrarrb(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b->top, c))
		i = ft_lstsize(b->top) - ft_find_place_b(b->top, c);
	if ((i < (ft_lstsize(a->top) - ft_find_index(a->top, c))) && ft_find_index(a->top, c))
		i = ft_lstsize(a->top) - ft_find_index(a->top, c);
	return (i);
}

int	ft_rrarb(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a->top, c))
		i = ft_lstsize(a->top) - ft_find_index(a->top, c);
	i = ft_find_place_b(b->top, c) + i;
	return (i);
}

int	ft_rarrb(t_pile *a, t_pile *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b->top, c))
		i = ft_lstsize(b->top) - ft_find_place_b(b->top, c);
	i = ft_find_index(a->top, c) + i;
	return (i);
}
