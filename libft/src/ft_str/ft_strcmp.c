/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:12:34 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/20 15:13:50 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			len;
	unsigned char	*str1;
	unsigned char	*str2;

	len = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[len] && str2[len] && str1[len] == str2[len])
		len++;
	return (str1[len] - str2[len]);
}
