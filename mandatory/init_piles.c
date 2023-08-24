#include "push_swap.h"

t_pile	*init_pile_a(int ac, char **av)
{
	t_pile	*pile_a;

	pile_a = malloc(sizeof(t_pile));
	if (!pile_a)
		return (NULL);
	pile_a->top = get_av(ac, av);
	if (!pile_a->top)
		return (free(pile_a), prog_error(), NULL);
	pile_a->full_len = ft_lstsize(pile_a->top);
	pile_a->actual_len = pile_a->full_len;
	pile_a->pre_sort = get_tab(pile_a);
	if (!pile_a->pre_sort)
		return (ft_free_stack(&(pile_a->top)), free(pile_a), prog_error(), NULL);
	ft_sort_int_tab(pile_a->pre_sort, pile_a->full_len);
	pile_a->nb_chunks = define_chunks(pile_a->full_len);
	if (pile_a->nb_chunks > 1)
	{
		define_pivots(pile_a);
	}
	return (pile_a);
}

t_pile	*init_pile_b(t_pile *pile_a)
{
	t_pile	*pile_b;

	pile_b = malloc(sizeof(t_pile));
	if (!pile_b)
		return (ft_free_stack(&(pile_a->top)), free(pile_a), NULL);
	pile_b->top = NULL;
	pile_b->full_len = 0;
	pile_b->actual_len = 0;
	pile_b->nb_chunks = pile_a->nb_chunks;
	pile_b->pre_sort = pile_a->pre_sort;
	pile_b->pivots = pile_a->pivots;
	pile_b->chunk_size[0] = pile_a->chunk_size[0];
	pile_b->chunk_size[1] = pile_a->chunk_size[1];
	return (pile_b);
}
