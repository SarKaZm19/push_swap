/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesb_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:34 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:12:43 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
}

void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_stacklast(*b);
	(*b)->next = tmp;
	(*b) = tmp->next;
	tmp->next = NULL;
}

void	ft_rrb(t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (!(*b) || !((*b)->next))
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}
