/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:12 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:17 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_first_two_chunks(t_pile *a, t_pile *b, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size && !ft_issorted(a->top) && a->actual_len > 3)
	{
		if (a->top->nbr < a->pivots[1])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr < a->pivots[0])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
			ft_ra(&(a->top), 0);
	}
}

static void	push_chunk(t_pile *a, t_pile *b, int index, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size && !ft_issorted(a->top) && a->actual_len > 3)
	{
		if (a->top->nbr <= a->pivots[index + 1])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr < a->pivots[index])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
			ft_ra(&(a->top), 0);
	}
}

void	push_one_chunk(t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	while (!ft_issorted(a->top) && a->actual_len > 3)
	{
		if (a->top->nbr <= a->pre_sort[a->full_len - 1])
		{
			ft_pb(&(a->top), &(b->top), 0);
			if (b->top->nbr < a->pivots[0])
				ft_rb(&(b->top), 0);
			a->actual_len--;
			b->actual_len++;
			i++;
		}
		else
			ft_ra(&(a->top), 0);
	}
}

void	push_b(t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	while (i < a->nb_chunks * 2 - 2)
	{
		if (i == 0)
			push_first_two_chunks(a, b, (a->full_len / a->nb_chunks) * 2);
		else if (i == a->nb_chunks * 2 - 4)
			push_one_chunk(a, b);
		else
			push_chunk(a, b, i, a->full_len / a->nb_chunks);
		i += 2;
	}
}
