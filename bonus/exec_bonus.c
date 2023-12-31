/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:20 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:08:20 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_op(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		ft_pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(a, b);
}
