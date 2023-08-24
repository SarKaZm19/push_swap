#include "push_swap.h"

int		define_chunks(int size)
{
	int nb_chunks;

	if (size < 50)
		nb_chunks = 1;
	else if (size < 300)
		nb_chunks = 3;
	else if (size < 600)
		nb_chunks = 6;
	else
		nb_chunks = 9;
	return (nb_chunks);
}

void	define_pivots(t_pile *pile)
{
	int	base_pivot;
	int	i;
	int	j;

	pile->pivots = malloc(sizeof(int) * ((pile->nb_chunks * 2) - 2));
	if (!pile->pivots)
		return ;
	base_pivot = (pile->full_len / pile->nb_chunks);
	j = 3;
	i = 2;
	pile->pivots[0] = pile->pre_sort[base_pivot];
	pile->pivots[1] = pile->pre_sort[base_pivot * 2];
	pile->chunk_size[0] = base_pivot;
	while (i < (pile->nb_chunks * 2) - 2)
	{
		if (i == (pile->nb_chunks * 2) - 4)
		{
			pile->pivots[i] = pile->pre_sort[pile->full_len - (base_pivot / 2)];
			pile->pivots[i + 1] = pile->pre_sort[pile->full_len - 1];
			pile->chunk_size[1] = pile->full_len - (base_pivot * (j - 1));
			i += 2;
		}
		else if (i % 2 == 1)
		{
			pile->pivots[i] = pile->pre_sort[(base_pivot * j)];
			i++;
			j++;
		}
		else if (i % 2 == 0)
		{
			pile->pivots[i] = pile->pre_sort[(base_pivot * j) - (base_pivot / 2)];
			i++;
		}
	}
}
