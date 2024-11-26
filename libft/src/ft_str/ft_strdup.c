/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:40:03 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 19:01:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Returns a pointer to a new string which is a duplicate of the string s.

char	*ft_strdup(const char *src)
{
	size_t	lensrc;
	char	*dest;

	lensrc = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * lensrc);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (char *)src, lensrc);
	return (dest);
}
