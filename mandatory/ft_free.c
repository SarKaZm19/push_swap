/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:31:29 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:39:18 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->nbr = 0;
		free(*a);
		(*a) = tmp;
	}
}

void	ft_free_pile(t_pile *pile, int print_error)
{
	if (pile)
	{
		if (pile->top)
			ft_free_stack(&(pile->top));
		if (pile->pre_sort)
		{
			free(pile->pre_sort);
			pile->pre_sort = NULL;
		}
		if (pile->pivots)
		{
			free(pile->pivots);
			pile->pivots = NULL;
		}
		free(pile);
		pile = NULL;
	}
	if (print_error == 1)
		prog_error();
}
