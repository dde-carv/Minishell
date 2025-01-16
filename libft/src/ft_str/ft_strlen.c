/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:25:19 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:29:31 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Calculates the length of the string pointed to by s.
//Returns the number of bytes in the string pointed to by s.

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str || !*str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
