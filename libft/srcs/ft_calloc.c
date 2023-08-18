/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:13:15 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/24 15:00:56 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_ptr;

	mem_ptr = malloc(nmemb * size);
	if (!mem_ptr)
		return (NULL);
	ft_bzero(mem_ptr, nmemb * size);
	return (mem_ptr);
}
