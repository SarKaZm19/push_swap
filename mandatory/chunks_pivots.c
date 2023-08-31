#include "push_swap.h"

int		define_chunks(int size)
{
	int nb_chunks;

	if (size < 100)
		nb_chunks = 1;
	else if (size < 300)
		nb_chunks = 3;
	else if (size < 600)
		nb_chunks = 6;
	else
		nb_chunks = size / 100;
	return (nb_chunks);
}

static void	get_pivots(int *arr, int *pivots, int nb_chunks, int base_pivot, int size)
{
	int	j;
	int	i;

	j = 3;
	i = 2;
	while (i < (nb_chunks * 2) - 2)
	{
		if (i == (nb_chunks * 2) - 4)
		{
			pivots[i] = arr[size - (base_pivot / 2)];
			pivots[i + 1] = arr[size - 1];
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
}

int	*set_pivots(int *arr, int nb_chunks, int size)
{
	int	*pivots;
	int	base_pivot;

	if (nb_chunks == 1)
		pivots = malloc(sizeof(int) * nb_chunks);
	else
		pivots = malloc(sizeof(int) * ((nb_chunks * 2) - 2));
	if (!pivots)
		return (NULL);
	if (nb_chunks > 1)
	{
		base_pivot = (size / nb_chunks);
		pivots[0] = arr[base_pivot];
		pivots[1] = arr[base_pivot * 2];
		get_pivots(arr, pivots, nb_chunks, base_pivot, size);
	}
	else
		pivots[0] = size / 2;
	return (pivots);
}
