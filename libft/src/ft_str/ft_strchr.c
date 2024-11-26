/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:24:59 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Returns a pointer to the first occurrence of the character c in the string s.

char	*ft_strchr(const char *str, int c)
{
	while (*str && c != *str)
		str++;
	if (c == *str)
		return ((char *)str);
	return (NULL);
}
