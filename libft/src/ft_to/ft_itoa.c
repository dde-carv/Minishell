/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:34 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 18:59:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Allocates a string representing the integer received as an argument.
//Returns the string representing the integer. NULL if the allocation fails.

static int	numcount(int n)
//Counts the number of digits in the integer received as an argument.
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = numcount(n);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = 48;
	else if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		len--;
		if (n < 0)
			ptr[len] = (-(n % 10)) + 48;
		else
			ptr[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}
