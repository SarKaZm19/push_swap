#include "push_swap.h"

void	push_first_two_chunks(t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	while (i < (a->chunk_size[0] * 2) + 1 && !ft_issorted(a->top))
	{
		if (a->top->nbr <= a->pivots[1])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr <= a->pivots[0])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
			ft_ra(&(a->top), 0);
	}
}

void	push_chunk(t_pile *a, t_pile *b, int index)
{
	int	i;

	i = 0;
	while (i < a->chunk_size[1] && !ft_issorted(a->top) && a->actual_len > 3)
	{
		if (a->top->nbr <= a->pivots[index + 1] && a->top->nbr < a->pre_sort[a->full_len - 3])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr <= a->pivots[index])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
		{
			ft_ra(&(a->top), 0);
		}
	}
}

void	push_b(t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	while (i < a->nb_chunks * 2 - 2)
	{
		if (i == 0)
			push_first_two_chunks(a, b);
		else if (i == (a->nb_chunks * 2) - 4)
			push_chunk(a, b, i);
		else
			push_chunk(a, b, i);
		i += 2;
	}
}
