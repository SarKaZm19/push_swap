#include "push_swap.h"

void	get_nb_rot_b(t_stack *tmp, t_stack *b, int len)
{
	tmp->nb_rot_b = ft_find_place_b(b, tmp->nbr);
	//tmp->nb_rev_rot_b = len - tmp->nb_rot_b;
	tmp->rev_b = 0;
	if (tmp->nb_rot_b > len / 2)
	{
		tmp->nb_rot_b = len - tmp->nb_rot_b;
		tmp->rev_b = 1;
	}
}

void	get_nb_rot_a(t_stack *tmp, int len, int index)
{
	tmp->nb_rot_a = index;
	//tmp->nb_rev_rot_a = len - index;
	tmp->rev_a = 0;
	if (index > len / 2)
	{
		tmp->nb_rot_a = len - index;
		tmp->rev_a = 1;
	}
}

void	get_total_moves(t_stack *tmp)
{
	//int	total_moves;
		
	if ((tmp->rev_a && tmp->rev_b) || (!tmp->rev_a && !tmp->rev_b))
	{
		if (tmp->nb_rot_a >= tmp->nb_rot_b)
			tmp->total_moves = tmp->nb_rot_a;
		else
			tmp->total_moves = tmp->nb_rot_b;
	}
	tmp->total_moves = tmp->nb_rot_a + tmp->nb_rot_b;
}

int	get_cheapest(t_pile *a, t_pile *b)
{
	int		cheapest_moves;
	int		index;
	t_stack	*tmp;

	cheapest_moves = a->full_len;
	index = 0;
	tmp = a->top;
	while (tmp)
	{
		get_nb_rot_a(tmp, a->actual_len, index);
		get_nb_rot_b(tmp, b->top, b->actual_len);
		get_total_moves(tmp);
		if (cheapest_moves > tmp->total_moves)
			cheapest_moves = tmp->total_moves;
		index++;
		tmp = tmp->next;
	}
	return (cheapest_moves);
}

int	select_candidates(t_stack *candidates)
{
	int	lowest; // maybe try with biggest / lowest just to see if there's a difference

	lowest = candidates->nbr;
	candidates = candidates->next;
	while (candidates)
	{
		if (lowest > candidates->nbr)
			lowest = candidates->nbr;
		candidates = candidates->next;
	}
	//printf("biggest : %d\n", biggest);
	return (lowest);
}

t_stack	*set_candidates(t_stack *a, int cheapest_moves)
{
	t_stack	*candidates;
	t_stack	*new_candidates;
	t_stack	*tmp;

	tmp = a;
	candidates = NULL;
	while (tmp)
	{
		if (tmp->total_moves == cheapest_moves)
		{
			new_candidates = ft_stack_new(tmp->nbr);
			if (!new_candidates)
				return (ft_free_stack(&candidates), NULL);
			ft_add_back(&candidates, new_candidates);
		}
		tmp = tmp->next;
	}
	// printf("candidates...\n");
	// print_stack(candidates);
	return (candidates);
}

t_stack	*ft_new_candidate(t_stack *elem)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->nbr = elem->nbr;
	new->nb_rot_a = elem->nb_rot_a;
	new->nb_rot_b = elem->nb_rot_b;
	new->total_moves = elem->total_moves;
	new->rev_a = elem->rev_a;
	new->rev_b = elem->rev_b;
	new->next = NULL;
	return (new);
}

void	apply_rotations(t_pile *a, t_pile *b, t_stack *candidates)
{
	
	if (!candidates->rev_a && !candidates->rev_b)
	{
		if (candidates->nb_rot_a >= candidates->nb_rot_b)
			while (candidates->nb_rot_b-- > 0)
			{
				ft_rr(a, b, 0);
				candidates->nb_rot_a--;
			}
		else
			while (candidates->nb_rot_a-- > 0)
			{
				ft_rr(a, b, 0);
				candidates->nb_rot_b--;
			}
	}
	else if (candidates->rev_a && candidates->rev_b)
	{
		if (candidates->nb_rot_a >= candidates->nb_rot_b)
			while (candidates->nb_rot_b-- > 0)
			{
				ft_rrr(a, b, 0);
				candidates->nb_rot_a--;
			}
		else
			while (candidates->nb_rot_a-- > 0)
			{
				ft_rrr(a, b, 0);
				candidates->nb_rot_b--;
			}
	}
	if (!candidates->rev_a)
		while (candidates->nb_rot_a-- > 0)
			ft_ra(a, 0);
	else
		while (candidates->nb_rot_a-- > 0)
			ft_rra(a, 0);
	if (!candidates->rev_b)	
		while (candidates->nb_rot_b-- > 0)
			ft_rb(b, 0);
	else	
		while (candidates->nb_rot_b-- > 0)
			ft_rrb(b, 0);
	ft_pb(a, b, 0);
}

void	ft_sort_b_till_3(t_pile *a, t_pile *b)
{
	t_stack	*tmp;
	t_stack *candidates;
	int		cheapest_moves;
	int		push_nb;

	push_nb = 0;
	// printf("coucouentrysortb\n");
	// printf("a->actual_len = %d\n", a->actual_len);
	while (a->actual_len > 3 && !ft_issorted(a->top))
	{
		// printf("loop\n");
		//candidates = NULL;
		cheapest_moves = get_cheapest(a, b);
		// printf("coucou after cheapest\n");
		candidates = set_candidates(a->top, cheapest_moves);
		/* print_stack(a->top);
		print_stack(b->top); */
		// printf("cocuou after set_candidates\n");
		/* if (!candidates)
			ft_free_all(a, b); */
		push_nb = select_candidates(candidates);
		//printf("push_nb = %d\n", push_nb);
		// printf("coucou after select candidates\n");
		// ft_free_stack(&candidates);
		tmp = a->top;
		while (tmp)
		{
			if (tmp->nbr == push_nb)
				break ;
			tmp = tmp->next;
		}
		// printf("tmp->nbr = %d\n", tmp->nbr);
		// print_stack(a->top);
		// print_stack(b->top);
		// printf("tmp->nb_rot_a = %d, tmp->nb_rot_b = %d, tmp->rev_a = %d, tmp->rev_b = %d, tmp->total_moves = %d\n", tmp->nb_rot_a, tmp->nb_rot_b, tmp->rev_a, tmp->rev_b, tmp->total_moves);
		// printf("coucou after loop to push_nb\n");
		apply_rotations(a, b, tmp);
		// printf("coucou after apply_rot\n");
	}
	// printf("coucououtsortb\n");
}

// Si pas mieux à push que le premier on push le premier 
// Le premier a 0 rot sur a et max b_len / 2 rot sur b
// catch le minimum de move cumulé dans a et b
// relire la stack pour récupérer les autres candidats sur ce nombre de move
// push le plus petit (ou plus grand)
// 1. Trouver les meilleures rotations loop dans tmp et ajouter les coups les moins chères à la stack
// 2. Appliquer
