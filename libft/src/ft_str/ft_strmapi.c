/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:07:09 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:29:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Applies the function f to each character of the string s
//Returns The string created from the successive applications of ’f’
// or NULL if the allocation fails.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;

	len = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[len])
	{
		str[len] = f(len, s[len]);
		len++;
	}
	str[len] = '\0';
	return (str);
}
