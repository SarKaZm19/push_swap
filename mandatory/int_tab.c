/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:31:52 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:31:52 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	sml;
	int	index;

	i = -1;
	while (++i < size)
	{
		sml = tab[i];
		j = i;
		while (++j < size)
		{
			if (tab[j] < sml)
			{
				sml = tab[j];
				index = j;
			}
		}
		if (sml != tab[i])
		{
			tab[index] = tab[i];
			tab[i] = sml;
		}
	}
}

int	*get_tab(t_pile *pile_a)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * pile_a->full_len);
	if (!arr)
		return (NULL);
	tmp = pile_a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	return (arr);
}
