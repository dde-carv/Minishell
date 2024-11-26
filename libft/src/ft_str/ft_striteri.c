/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:59:25 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:29:09 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Applies the function ’f’ on each character of the string passed as argument.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;

	len = 0;
	if (!s || !f)
		return ;
	while (s[len])
	{
		f(len, s + len);
		len++;
	}
}
