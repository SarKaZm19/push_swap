#include "push_swap.h"

int	ft_apply_rarb(t_pile *a, t_pile *b, int to_find)
{

	while (b->top->nbr != to_find && ft_find_place_a(a->top, to_find) > 0)
		ft_rr(&(a->top), &(b->top), 0);
	while (b->top->nbr != to_find)
		ft_rb(&(b->top), 0);
	while (ft_find_place_a(a->top, to_find) > 0)
		ft_ra(&(a->top), 0);
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
	return (-1);
}

int	ft_apply_rrarrb(t_pile *a, t_pile *b, int to_find)
{
	while (b->top->nbr != to_find && ft_find_place_a(a->top, to_find) > 0)
	{
		print_stack(a->top);
		printf("to_find = %d\n", to_find);
		ft_rrr(&(a->top), &(a->top), 0);
	}
	while (b->top->nbr != to_find)
		ft_rrb(&(b->top), 0);
	while (ft_find_place_a(a->top, to_find) > 0)
		ft_rra(&(a->top), 0);
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
	return (-1);
}

int	ft_apply_rrarb(t_pile *a, t_pile *b, int to_find)
{
	while (ft_find_place_a(a->top, to_find) > 0)
		ft_rra(&(a->top), 0);
	while (b->top->nbr != to_find)
		ft_rb(&(b->top), 0);
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
	return (-1);
}

int	ft_apply_rarrb(t_pile *a, t_pile *b, int to_find)
{
	while (ft_find_place_a(a->top, to_find) > 0)
		ft_ra(&(a->top), 0);
	while (b->top->nbr != to_find)
		ft_rrb(&(b->top), 0);
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
	return (-1);
}