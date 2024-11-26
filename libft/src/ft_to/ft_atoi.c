/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:47:23 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:26:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Convert a string (ascii) to an integer.
//Returns the converted value or 0 on error.

int	ft_atoi(const char *str)
{
	int	len;
	int	neg;
	int	nb;

	len = 0;
	neg = 1;
	nb = 0;
	while (str[len] == 12 || str[len] == 10 || str[len] == 13
		|| str[len] == 9 || str[len] == 11 || str[len] == 32)
		len++;
	if (str[len] == 43)
		len++;
	else if (str[len] == 45)
	{
		neg *= -1;
		len++;
	}
	while (ft_isdigit(str[len]))
	{
		nb = (nb * 10) + (str[len] - 48);
		len++;
	}
	nb = nb * neg;
	return (nb);
}
