#include "push_swap.h"

void	push_first_two_chunks(t_pile *a, t_pile *b, int chunk_size)
{
	//printf("chunk_size = %d\n", chunk_size);
	int	i;

	i = 0;
	while (i <= chunk_size && !ft_issorted(a->top) && a->actual_len > 3)
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

void	push_chunk(t_pile *a, t_pile *b, int index, int chunk_size)
{
	int	i;

	i = 0;
	//printf("chunk_size = %d\n", chunk_size);
	while (i < chunk_size && !ft_issorted(a->top) && a->actual_len > 3)
	{
		if (a->top->nbr <= a->pivots[index + 1])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr <= a->pivots[index])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
			ft_ra(&(a->top), 0);	
	}
}

void	push_b(t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	while (i < a->nb_chunks * 2 - 2)
	{
		if (i == 0)
		{
			push_first_two_chunks(a, b, (a->full_len / a->nb_chunks) * 2);
			i += 2;
		}
		//printf("pivots[%d] = %d, chunk_size = %d\n", i, pivots[i], a->full_len / nb_chunks);
		push_chunk(a, b, i, a->full_len / a->nb_chunks);
		i += 2;
	}
}
