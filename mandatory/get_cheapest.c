#include "push_swap.h"

int get_cheapest(t_pile *a, t_pile *b)
{
	int		cheapest_moves;
	int		index;
	int		nb_push;
	t_stack	*tmp;

	cheapest_moves = a->full_len;
	index = 0;
	tmp = b->top;
	while (tmp)
	{
		get_nb_rot_a(tmp, a->top, a->actual_len);
		get_nb_rot_b(tmp, b->actual_len, index);
		get_total_moves(tmp);
		if (cheapest_moves > tmp->total_moves)
		{
			cheapest_moves = tmp->total_moves;
			nb_push = tmp->nbr;
		}
		index++;
		tmp = tmp->next;
	}
	return (nb_push);
}
