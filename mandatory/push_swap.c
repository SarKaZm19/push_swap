/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:15 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:26 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_to_top(t_pile *a)
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
		push_a(a, b);
		rotate_min_to_top(a);
	}
}
