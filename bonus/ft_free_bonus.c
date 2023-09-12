/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:22 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:09:53 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_operations(t_list **ops)
{
	t_list	*tmp;

	if (!ops)
		return ;
	while (*ops)
	{
		tmp = (*ops)->next;
		free((*ops)->content);
		(*ops)->content = NULL;
		free(*ops);
		(*ops) = tmp;
	}
}

void	ft_free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		(*s)->nbr = 0;
		free(*s);
		(*s) = tmp;
	}
}
