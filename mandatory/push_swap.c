#include "push_swap.h"

void	print_tab(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	rotate_min_to_top(t_pile *a)
{
	int	i;

	i = ft_find_index(a->top, ft_min(a->top));
	if (i < ft_lstsize(a->top) - i)
	{
		while (a->top->nbr != ft_min(a->top))
			ft_ra(&(a->top), 0);
	}
	else
	{
		while (a->top->nbr != ft_min(a->top))
			ft_rra(&(a->top), 0);
	}
}

void	push_swap(t_pile *a, t_pile *b)
{
	t_stack	*to_move;
	int		nb_push;
	int		i;
	int		c_size;
	int		j;
	int		tmp_a_size;

	b->top = NULL;
	if (a->full_len == 2)
		ft_sa(&(a->top), 0);
	else if (a->full_len == 3)
		ft_sort_three(&(a->top));
	if (a->full_len > 3)
	{
		if (a->nb_chunks == 1)
		{
			//printf("nb_chunks = %d\n", nb_chunks);
		}
		else
		{
			push_b(a, b);
		}
		if (!ft_issorted(a->top))
			ft_sort_three(&(a->top));
		//print_info(a);
		i = a->nb_chunks * 2 - 4;
		//printf("pivots[%d] = %d\n", i, a->pivots[i]);
		c_size = 0;
		//printf("a->full_len = %d\n", a->full_len);
		tmp_a_size = a->actual_len;
		j = 0;
		while (j < a->full_len)
		{
			if (a->pre_sort[j] > a->pivots[i] && a->pre_sort[j] <= a->pivots[i + 1])
				c_size++;
			j++;
		}
		c_size -= tmp_a_size;
		tmp_a_size -= c_size;
		//printf("j pre_sortindex = %d, tmp_a_size = %d, c_size = %d\n", j, tmp_a_size, c_size);
		if (c_size <= 0)
		{
			i -= 1;
			j = 0;
			c_size = 0;
			while (j < a->full_len)
			{
				if (a->pre_sort[j] > a->pivots[i] && a->pre_sort[j] <= a->pivots[i + 1])
					c_size++;
				j++;
			}
		}
		if (tmp_a_size > 0)
		{
			c_size -= tmp_a_size;
			tmp_a_size -= c_size;
		}
		//print_stack(a->top);
		//fprintf(stderr, "c_size = %d, a->len = %d, b->len = %d, i = %d, pivots[i] = %d, pivots[i + 1] = %d\n", c_size, a->actual_len, b->actual_len, i, a->pivots[i], a->pivots[i + 1]);
		while(b->actual_len)
		{
			nb_push = get_cheapest(a, b, i); // faire cheapest from chunk ;)
			//print_stack(a->top);
			fprintf(stderr, "nb_push = %d\n", nb_push);
			to_move = b->top;
			while (to_move)
			{
				if (to_move->nbr == nb_push)
					break ;
				to_move = to_move->next;
			}
			push_a(a, b, to_move);
			c_size--;
			if (c_size <= 0 && b->actual_len)
			{
				i -= 1;
				j = 0;
				c_size = 0;
				while (j < a->full_len)
				{
					if (i >= 0 && (a->pre_sort[j] > a->pivots[i] && a->pre_sort[j] <= a->pivots[i + 1]))
						c_size++;
					else if (i == -1)
						c_size = b->actual_len;
					j++;
				}
				fprintf(stderr, "c_size = %d, a->len = %d, b->len = %d, i = %d, pivots[i] = %d, pivots[i + 1] = %d\n", c_size, a->actual_len, b->actual_len, i, a->pivots[i], a->pivots[i + 1]);
			}
		}
		//printf("len_a = %d len_b = %d\n", a->actual_len, b->actual_len);
		/* printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top); */
		/* i = a->nb_chunks * 2 - 4;
		print_stack(a->top);
		c_size = (a->chunk_size[1] / 2) - a->actual_len - (a->chunk_size[0] - a->chunk_size[1]);
		while (b->actual_len != 0)
		{
			nb_push = get_cheapest(a, b, i); // faire cheapest from chunk ;)
			fprintf(stderr, "nb_push = %d\n", nb_push);
			to_move = b->top;
			while (to_move)
			{
				if (to_move->nbr == nb_push)
					break ;
				to_move = to_move->next;
			}
			push_a(a, b, to_move);
			printf("c_size = %d\n", c_size);
			printf("i = %d\n", i);
			c_size--;
			if (c_size <= 0)
			{
				i -= 2;
				if (i >= 0)
					c_size = a->chunk_size[1];
				else
					c_size = a->chunk_size[0] - 1;	
			}
		}  */
		/* printf("len_a = %d, len_b = %d\n", a->actual_len, b->actual_len);
		printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top); */
		rotate_min_to_top(a);
	}
}
