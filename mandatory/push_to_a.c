#include "push_swap.h"

void	push_a(t_pile *a, t_pile *b, t_stack *to_move)
{
	while (to_move->nb_rr > 0)
	{
		ft_rr(&(a->top), &(b->top), 0);
		to_move->nb_rr--;
	}
	while (to_move->nb_rrr > 0)
	{
		ft_rrr(&(a->top), &(b->top), 0);
		to_move->nb_rrr--;
	}
	if (to_move->rev_a)
	{
		while (to_move->nb_rot_a > 0)
		{
			ft_rra(&(a->top), 0);
			to_move->nb_rot_a--;
		}
	}
	else
	{
		while (to_move->nb_rot_a > 0)
		{
			ft_ra(&(a->top), 0);
			to_move->nb_rot_a--;
		}
	}
	if (to_move->rev_b)
	{
		while (to_move->nb_rot_b > 0)
		{
			ft_rrb(&(b->top), 0);
			to_move->nb_rot_b--;
		}
	}
	else
	{
		while (to_move->nb_rot_b > 0)
		{
			ft_rb(&(b->top), 0);
			to_move->nb_rot_b--;
		}
	}
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
}
