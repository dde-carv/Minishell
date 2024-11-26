/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:11 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 14:33:33 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Scans  the  initial n bytes of the memory area
// pointed to by s for the first instance of c.
//Return a pointer to the matching byte or
// NULL if the character does not occur in the given memory area.

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			len;
	unsigned char	*ptr;
	unsigned char	chr;

	len = 0;
	chr = (unsigned char)c;
	ptr = (unsigned char *)str;
	while (len < n)
	{
		if (ptr[len] == chr)
			return ((void *)(str + len));
		len++;
	}
	return (NULL);
}
