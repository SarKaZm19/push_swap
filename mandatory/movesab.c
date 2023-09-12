/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:06 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:33:41 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
