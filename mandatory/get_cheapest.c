#include "push_swap.h"

static void	get_nb_rot_a(t_stack *tmp, t_stack *a, int len)
{
	tmp->nb_rot_a = ft_find_place_a(a, tmp->nbr);
	tmp->rev_a = 0;
	if (tmp->nb_rot_a > len / 2)
	{
		tmp->nb_rot_a = len - tmp->nb_rot_a;
		tmp->rev_a = 1;
	}
}

static void	get_nb_rot_b(t_stack *tmp, int len, int index)
{
	tmp->nb_rot_b = index;
	tmp->rev_b = 0;
	if (index > len / 2)
	{
		tmp->nb_rot_b = len - index;
		tmp->rev_b = 1;
	}
}

static void	get_total_moves(t_stack *tmp)
{
	if ((tmp->rev_a && tmp->rev_b) || (!tmp->rev_a && !tmp->rev_b))
	{
		if (tmp->rev_a)
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
		else if (!tmp->rev_a)
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
	}
	else
	{
		tmp->nb_rr = 0;
		tmp->nb_rrr = 0;
		tmp->total_moves = tmp->nb_rot_a + tmp->nb_rot_b;
	}
}

int get_cheapest(t_pile *a, t_pile *b, int index_chunk)
{
	int		cheapest_moves;
	int		index_tmp;
	int		nb_push;
	t_stack	*tmp;

	printf("coucou\n");
	cheapest_moves = a->full_len;
	index_tmp = 0;
	tmp = b->top;
	nb_push = tmp->nbr;
	while (tmp)
	{

		if (index_chunk == -2 || (tmp->nbr <= a->pivots[index_chunk + 1] && tmp->nbr > a->pivots[index_chunk]))
		{
			get_nb_rot_a(tmp, a->top, a->actual_len);
			get_nb_rot_b(tmp, b->actual_len, index_tmp);
			get_total_moves(tmp);
			if (cheapest_moves > tmp->total_moves)
			{
				printf("tmp->nbr = %d\n", tmp->nbr);
				cheapest_moves = tmp->total_moves;
				nb_push = tmp->nbr;
			}
		}
		index_tmp++;
		tmp = tmp->next;
	}
	return (nb_push);
}