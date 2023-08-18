/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:15:47 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/24 15:17:53 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	if (!dest && !src)
		return (NULL);
	tmpdst = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	i = 0;
	if ((size_t)dest < (size_t)src)
	{
		while (n--)
			*(tmpdst++) = *(tmpsrc++);
	}
	else
		while (++i <= n)
			tmpdst[n - i] = tmpsrc[n - i];
	return (dest);
}
