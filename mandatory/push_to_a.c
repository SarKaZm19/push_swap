/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:17 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:35:45 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sync_rot(t_pile *a, t_pile *b, t_stack *to_move)
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
}

static void	do_rot_a(t_pile *a, t_stack *to_move)
{
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
}

static void	do_rot_b(t_pile *b, t_stack *to_move)
{
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
}

static void	rotate_push_a(t_pile *a, t_pile *b, t_stack *to_move)
{
	do_sync_rot(a, b, to_move);
	do_rot_a(a, to_move);
	do_rot_b(b, to_move);
	ft_pa(&(a->top), &(b->top), 0);
	a->actual_len++;
	b->actual_len--;
}

void	push_a(t_pile *a, t_pile *b)
{
	t_stack	*to_move;
	int		nb_push;

	while (b->actual_len != 0)
	{
		nb_push = get_cheapest(a, b);
		to_move = b->top;
		while (to_move)
		{
			if (to_move->nbr == nb_push)
				break ;
			to_move = to_move->next;
		}
		rotate_push_a(a, b, to_move);
	}
}
