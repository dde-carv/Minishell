/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:25:27 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:29:39 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Compares the first nbytes of the strings s1 and s2.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len;
	unsigned char	*str1;
	unsigned char	*str2;

	len = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[len] && str2[len] && str1[len] == str2[len] && n > 1)
	{
		len++;
		n--;
	}
	return (str1[len] - str2[len]);
}
