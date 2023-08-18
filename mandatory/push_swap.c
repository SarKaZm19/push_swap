#include "push_swap.h"

void	ft_sort_three(t_pile *a)
{
	if (ft_min(a->top) == a->top->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(a->top) == a->top->nbr)
	{
		ft_ra(a, 0);
		if (!ft_issorted(a->top))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(a->top, ft_max(a->top)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

/* void	ft_sort_b_max_3(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(a->top) > 3 && !ft_issorted(a->top))
	{
		tmp = a->top;
		i = find_best_rotation_atob(a, b);
		while (i >= 0)
		{
			if (i == ft_rarb(a, b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarrb(a, b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rarrb(a, b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarb(a, b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
	//fprintf(stderr, "i = %d, stack->nbr = %d\n", i, tmp->nbr);
} */

t_pile	*ft_sort_b(t_pile *a, t_pile *b)
{
	if (a->actual_len > 3 && !ft_issorted(a->top))
		ft_pb(a, b, 0);
	if (a->actual_len > 3 && !ft_issorted(a->top))
		ft_pb(a, b, 0);
	if (a->actual_len > 3 && !ft_issorted(a->top))
		ft_sort_b_till_3(a, b);
	if (!ft_issorted(a->top))
		ft_sort_three(a);
	return (b);
}

t_pile	*ft_sort_a(t_pile *a, t_pile *b)
{
	int		i;
	t_stack	*tmp;

	while (b->top)
	{
		tmp = b->top;
		i = find_best_rotation_btoa(a, b);
		while (i >= 0)
		{
			if (i == ft_rarb_a(a, b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'b');
			else if (i == ft_rarrb_a(a, b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_rrarrb_a(a, b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_rrarb_a(a, b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

void make_biggest_to_top(t_pile *b)
{
	int biggest;
	int	pos;
	int	b_size;
	int nb_rot;

	biggest = ft_max(b->top);
	pos = ft_find_index(b->top, biggest);
	b_size = b->actual_len;
	//fprintf(stderr, "b_size = %d && b_actual_len = %d\n", b_size, b->actual_len);
	//fprintf(stderr, "b_size = %d, pos = %d, max_low = %d, max_up = %d\n", b_size, pos, (b_size / 10) * 3, (b_size / 10) * 8);
	/* if (pos > ((b_size / 10) * 3) && pos < ((b_size / 10) * 8))
		return ; */
	if (pos <= b_size / 2)
	{
		nb_rot = pos;
		while (nb_rot-- > 0)
			ft_rb(b, 0);
	}	 
	else
	{
		nb_rot = b_size - pos;
		while (nb_rot-- > 0)
			ft_rrb(b, 0);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	sml;
	int	index;

	i = -1;
	while (++i < size)
	{
		sml = tab[i];
		j = i;
		while (++j < size)
		{
			if (tab[j] < sml)
			{
				sml = tab[j];
				index = j;
			}
		}
		if (sml != tab[i])
		{
			tab[index] = tab[i];
			tab[i] = sml;
		}
	}
}

int	*get_tab(t_pile *pile_a)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * pile_a->full_len);
	if (!arr)
		return (NULL);
	tmp = pile_a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	return (arr);
}

void	print_tab(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

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

int	*define_pivots(int *arr, int nb_chunks, int size)
{
	int	*pivots;
	int	i;
	int	base_pivot;
	int	j;

	pivots = malloc(sizeof(int) * (nb_chunks));
	if (!pivots)
		return (NULL);
	base_pivot = (size / nb_chunks);
	j = 1;
	i = 0;
	/* if (nb_chunks >= 3)
	{
		pivots[0] = arr[base_pivot]; 
		printf("pivots[0] = %d\n", pivots[0]);
		pivots[1] = arr[base_pivot * 2];
		printf("pivots[1] = %d\n", pivots[1]);
		i = 2;
	}
	while (i < nb_chunks)
	{
		pivots[i] = arr[(base_pivot * j) + (base_pivot / 2)];
		printf("arr[%d] = %d\n", (base_pivot * j) + (base_pivot / 2), arr[(base_pivot * j) + (base_pivot / 2)]);
		printf("pivots[%d] = %d\n", i, pivots[i]);
		i++;
		j++;
	} */
	while (i < nb_chunks)
	{
		pivots[i] = arr[(base_pivot * j)];
		if (i == nb_chunks - 1)
			pivots[i] = arr[size - 1];
		else
			pivots[i] = arr[(base_pivot * j)];
		printf("arr[%d] = %d\n", (base_pivot * j), arr[(base_pivot * j)]);
		printf("pivots[%d] = %d\n", i, pivots[i]);
		i++;
		j++;
	}
	return (pivots);
}

void	push_swap(t_pile *a, t_pile *b)
{
	int		i;
	int		*pre_sort;
	int		nb_chunks;
	int		*pivots;

	b->top = NULL;
	if (a->full_len == 2)
		ft_sa(a, 0);
	else if (a->full_len == 3)
		ft_sort_three(a);
	else
	{
		pre_sort = get_tab(a);
		if (!pre_sort)
			return (ft_free_all(a, b), prog_error());
		ft_sort_int_tab(pre_sort, a->full_len);
		nb_chunks = define_chunks(a->full_len);
		printf("nb_chunks = %d\n", nb_chunks);
		if (nb_chunks != 1)
			pivots = define_pivots(pre_sort, nb_chunks, a->full_len);
		i = 0;
		//int	first_chunk_pivot = 

		while (i < nb_chunks)
		{
			//push_two_first_chunks
			i++;
		}
		(void)pivots;

		//boucle sur chunks, 2 premiers gratuit à accomoder
		// verif du pivot àpd 3eme








		//b = ft_sort_b(a, b);
		/*printf("len a = %d\n", a->actual_len);
		print_stack(a->top);
		printf("len b = %d\n", b->actual_len);
		print_stack(b->top); */
		/* make_biggest_to_top(b);
		a = ft_sort_a(a, b);
		i = ft_find_index(a->top, ft_min(a->top));
		if (i < ft_lstsize(a->top) - i)
		{
			while (a->top->nbr != ft_min(a->top))
				ft_ra(a, 0);
		}
		else
		{
			while (a->top->nbr != ft_min(a->top))
				ft_rra(a, 0);
		} */
	}
}
