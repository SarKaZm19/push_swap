/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:31:57 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 14:54:42 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->nbr < lst->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = init_pile_a(ac, av);
	pile_b = init_pile_b(pile_a);
	if (!ft_issorted(pile_a->top))
		push_swap(pile_a, pile_b);
	ft_free_pile(pile_a, 0);
	free(pile_b);
	return (0);
}
