#include "push_swap.h"

int	ft_apply_rarb(t_pile *a, t_pile *b, int to_find, char stack)
{
	if (stack == 'a')
	{
		while (a->top->nbr != to_find && ft_find_place_b(b->top, to_find) > 0)
			ft_rr(a, b, 0);
		while (a->top->nbr != to_find)
			ft_ra(a, 0);
		while (ft_find_place_b(b->top, to_find) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (b->top->nbr != to_find && ft_find_place_a(a->top, to_find) > 0)
			ft_rr(a, b, 0);
		while (b->top->nbr != to_find)
			ft_rb(b, 0);
		while (ft_find_place_a(a->top, to_find) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_pile *a, t_pile *b, int to_find, char stack)
{
	if (stack == 'a')
	{
		while (a->top->nbr != to_find && ft_find_place_b(b->top, to_find) > 0)
			ft_rrr(a, b, 0);
		while (a->top->nbr != to_find)
			ft_rra(a, 0);
		while (ft_find_place_b(b->top, to_find) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (b->top->nbr != to_find && ft_find_place_a(a->top, to_find) > 0)
			ft_rrr(a, b, 0);
		while (b->top->nbr != to_find)
			ft_rrb(b, 0);
		while (ft_find_place_a(a->top, to_find) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rrarb(t_pile *a, t_pile *b, int to_find, char stack)
{
	if (stack == 'a')
	{
		while (a->top->nbr != to_find)
			ft_rra(a, 0);
		while (ft_find_place_b(b->top, to_find) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(a->top, to_find) > 0)
			ft_rra(a, 0);
		while (b->top->nbr != to_find)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_apply_rarrb(t_pile *a, t_pile *b, int to_find, char stack)
{
	if (stack == 'a')
	{
		while (a->top->nbr != to_find)
			ft_ra(a, 0);
		while (ft_find_place_b(b->top, to_find) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(a->top, to_find) > 0)
			ft_ra(a, 0);
		while (b->top->nbr != to_find)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}