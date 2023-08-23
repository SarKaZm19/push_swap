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

int	*define_pivots(int *arr, int nb_chunks, int size, int *chunk_size)
{
	int	*pivots;
	int	i;
	int	base_pivot;
	int	j;

	pivots = malloc(sizeof(int) * ((nb_chunks * 2) - 2));
	if (!pivots)
		return (NULL);
	base_pivot = (size / nb_chunks);
	j = 3;
	i = 2;
	pivots[0] = arr[base_pivot];
	pivots[1] = arr[base_pivot * 2];
	chunk_size[0] = base_pivot;
	while (i < (nb_chunks * 2) - 2)
	{
		if (i == (nb_chunks * 2) - 4)
		{
			pivots[i] = arr[size - (base_pivot / 2)];
			pivots[i + 1] = arr[size - 1];
			chunk_size[1] = size - (base_pivot * (j - 1));
			i += 2;
		}
		else if (i % 2 == 1)
		{
			pivots[i] = arr[(base_pivot * j)];
			i++;
			j++;
		}
		else if (i % 2 == 0)
		{
			pivots[i] = arr[(base_pivot * j) - (base_pivot / 2)];
			i++;
		}
	}
	return (pivots);
}
