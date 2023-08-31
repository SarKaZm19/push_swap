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

	b->top = NULL;
	if (a->full_len == 2)
		ft_sa(&(a->top), 0);
	else if (a->full_len == 3)
		ft_sort_three(&(a->top));
	else
	{
		if (a->nb_chunks == 1)
			push_one_chunk(a, b);
		else
			push_b(a, b);
		if (!ft_issorted(a->top))
			ft_sort_three(&(a->top));
		//printf("len_a = %d len_b = %d\n", a->actual_len, b->actual_len);
		/* printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top); */
		//i = nb_chunks * 2 - 4;
		push_a(a, b);
		/* printf("len_a = %d, len_b = %d\n", a->actual_len, b->actual_len);
		printf("a>>>\n");
		print_stack(a->top);
		printf("b>>>\n");
		print_stack(b->top); */
		rotate_min_to_top(a);
	}
}
