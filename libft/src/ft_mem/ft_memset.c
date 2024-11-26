/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:52 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 14:18:41 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Fills the first n bytes of the memory area pointed to by
// s with the constant byte c.
//Returns a pointer to the memory area s.

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		((unsigned char *)str)[len] = c;
		len++;
	}
	return (str);
}
