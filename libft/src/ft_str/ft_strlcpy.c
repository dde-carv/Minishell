/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:25:13 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:29:25 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//copies up to size - 1 characters from the NUL-terminated string
// src to dst, NUL-terminating the result.
//Return the total length of the string they tried to create.

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	lensrc;

	len = 0;
	lensrc = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (lensrc);
	while ((len < (size - 1)) && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (lensrc);
}
