#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_issorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
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

	pivots = malloc(sizeof(int) * ((nb_chunks * 2) - 2));
	if (!pivots)
		return (NULL);
	base_pivot = (size / nb_chunks);
	j = 3;
	i = 2;
	pivots[0] = arr[base_pivot];
	pivots[1] = arr[base_pivot * 2];
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
	return (pivots);
}

void	get_nb_rot_a(t_stack *tmp, t_stack *a, int len)
{
	tmp->nb_rot_a = ft_find_place_a(a, tmp->nbr);
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

void	get_total_moves(t_stack *tmp)
{
	//int	total_moves;
		
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

void	push_swap(t_pile *a, t_pile *b)
{
	//t_stack	*to_move;
	int		i;
	int		*pre_sort;
	int		nb_chunks;
	int		*pivots;
	//int		nb_push;

	b->top = NULL;
	if (a->full_len == 2)
		ft_sa(&(a->top), 0);
	else if (a->full_len == 3)
		ft_sort_three(&(a->top));
	if (a->full_len > 3)
	{
		pre_sort = get_tab(a);
		if (!pre_sort)
			return (ft_free_all(a, b), prog_error());
		ft_sort_int_tab(pre_sort, a->full_len);
		nb_chunks = define_chunks(a->full_len);
		printf("nb_chunks = %d\n", nb_chunks);
		
		i = 0;
		if (nb_chunks == 1)
		{
			//printf("nb_chunks = %d\n", nb_chunks);
		}
		else
		{
			pivots = define_pivots(pre_sort, nb_chunks, a->full_len);
			i = -1;
			while (++i < nb_chunks * 2 - 2)
				printf("pivots[%d] = %d\n", i, pivots[i]);
			push_b(a, b, pivots, nb_chunks);
		}
		if (!ft_issorted(a->top))
			ft_sort_three(&(a->top));
		//printf("len_a = %d len_b = %d\n", a->actual_len, b->actual_len);
		printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top);
		//i = nb_chunks * 2 - 3;
		/* while (b->actual_len != 0)
		{
			nb_push = get_cheapest(a, b); // faire cheapest from chunk ;)
			to_move = b->top;
			while (to_move)
			{
				if (to_move->nbr == nb_push)
					break ;
				to_move = to_move->next;
			}
			 if (to_move->nbr == 44 || to_move->nbr == 19)
			{
				printf("nbr = %d rot_b = %d rot_a = %d rev_a = %d rev_b = %d nb_rr = %d nb_rrr = %d total_moves = %d\n", to_move->nbr, to_move->nb_rot_b, to_move->nb_rot_a, to_move->rev_a, to_move->rev_b, to_move->nb_rr, to_move->nb_rrr, to_move->total_moves);
				print_stack(a->top);
				print_stack(b->top);
			} */
			//push_a(a, b, to_move);
		//}
		// test avec  ./push_swap 65 99 53 20 3 85 35 87 81 15 11 19 44 7 96 74 79 54 40 98 33 34 39 6 100 60 31 70 48 68 55 72 37 24 46 29 75 45 42 25 43 47 2 94 5 67 41 77 63 28 95 73 64 32 89
		/* printf("len_a = %d, len_b = %d\n", a->actual_len, b->actual_len);
		printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top); */
		/* i = ft_find_index(a->top, ft_min(a->top));
		if (i < ft_lstsize(a->top) - i)
		{
			while (a->top->nbr != ft_min(a->top))
				ft_ra(&(a->top), 0);
		}
		else
		{
			while (a->top->nbr != ft_min(a->top))
				ft_rra(&(a->top), 0);
		} */
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
