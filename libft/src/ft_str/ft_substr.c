/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:00:01 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 19:11:41 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Allocates and returns a substring from the string ’s’ or NULL if
// alloaction fails. The substring begins at index ’start’ and is of
// maximum size ’len’.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
