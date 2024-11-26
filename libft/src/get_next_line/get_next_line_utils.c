/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:55:58 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/10 12:14:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n' )
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	totallen;
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = -1;
	totallen = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	str = malloc(sizeof(char) * totallen + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[len1])
	{
		str[len1] = s1[len1];
		len1++;
	}
	while (s2[++len2])
	{
		str[len1++] = s2[len2];
		if (s2[len2] == '\n')
			break ;
	}
	str[len1] = '\0';
	free (s1);
	return (str);
}
