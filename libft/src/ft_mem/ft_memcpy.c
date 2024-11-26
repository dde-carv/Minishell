/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:24 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 14:34:21 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Copies n bytes from memory area src to memory area dest.
// The memory areas must not overlap.
//Returns a pointer to dest.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			len;
	unsigned char	*dst;
	unsigned char	*sorce;

	len = 0;
	dst = (unsigned char *)dest;
	sorce = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (len < n)
	{
		dst[len] = sorce[len];
		len++;
	}
	return (dst);
}
