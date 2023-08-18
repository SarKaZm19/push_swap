/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:12:50 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/28 18:30:26 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long			nb;
	size_t			i;
	int				sign;
	unsigned char	*tmp;

	sign = 1;
	nb = 0;
	i = 0;
	tmp = (unsigned char *)nptr;
	while (ft_isspace(tmp[i]))
		i++;
	if (tmp[i] == '+' || tmp[i] == '-')
	{
		if (tmp[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(tmp[i]))
	{
		nb = nb * 10 + tmp[i] - 48;
		i++;
	}
	return (sign * nb);
}
