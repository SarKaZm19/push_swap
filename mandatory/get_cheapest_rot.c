#include "push_swap.h"

void	get_nb_rot_a(t_stack *tmp, t_stack *a, int len)
{
	tmp->nb_rot_a = ft_find_place(a, tmp->nbr);
	tmp->rev_a = 0;
	if (tmp->nb_rot_a > len / 2)
	{
		tmp->nb_rot_a = len - tmp->nb_rot_a;
		tmp->rev_a = 1;
	}
}

void	get_nb_rot_b(t_stack *tmp, int len, int index)
{
	tmp->nb_rot_b = index;
	tmp->rev_b = 0;
	if (index > len / 2)
	{
		tmp->nb_rot_b = len - index;
		tmp->rev_b = 1;
	}
}

static void	get_nb_rrr(t_stack *tmp)
{
	if (tmp->nb_rot_a >= tmp->nb_rot_b)
	{
		tmp->nb_rrr = tmp->nb_rot_b;
		tmp->nb_rot_a -= tmp->nb_rot_b;
		tmp->nb_rot_b = 0;
		tmp->total_moves = tmp->nb_rot_a + tmp->nb_rrr;
	}
	else
	{
		tmp->nb_rrr = tmp->nb_rot_a;
		tmp->nb_rot_b -= tmp->nb_rot_a;
		tmp->nb_rot_a = 0;
		tmp->total_moves = tmp->nb_rot_b + tmp->nb_rrr;
	}
	tmp->nb_rr = 0;
}

static void	get_nb_rr(t_stack *tmp)
{
	if (tmp->nb_rot_a >= tmp->nb_rot_b)
	{
		tmp->nb_rr = tmp->nb_rot_b;
		tmp->nb_rot_a = tmp->nb_rot_a - tmp->nb_rot_b;
		tmp->nb_rot_b = 0;
		tmp->total_moves = tmp->nb_rot_a + tmp->nb_rr;
	}
	else
	{
		tmp->nb_rr = tmp->nb_rot_a;
		tmp->nb_rot_b -= tmp->nb_rot_a;
		tmp->nb_rot_a = 0;
		tmp->total_moves = tmp->nb_rot_b + tmp->nb_rr;
	}
	tmp->nb_rrr = 0;
}

void	get_total_moves(t_stack *tmp)
{
	if ((tmp->rev_a && tmp->rev_b) || (!tmp->rev_a && !tmp->rev_b))
	{
		if (tmp->rev_a)
			get_nb_rrr(tmp);
		else if (!tmp->rev_a)
			get_nb_rr(tmp);
	}
	else
	{
		tmp->nb_rr = 0;
		tmp->nb_rrr = 0;
		tmp->total_moves = tmp->nb_rot_a + tmp->nb_rot_b;
	}
}