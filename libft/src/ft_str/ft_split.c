/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:07:55 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 18:53:18 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter.
//Returns the array of new strings resulting from the split.
// NULL if the allocation fails.

static int	safe_allocation(char **word_p, int position, size_t len)
{
	int	i;

	i = 0;
	word_p[position] = malloc(len);
	if (!word_p[position])
	{
		while (i < position)
		{
			free(word_p[i]);
			i++;
		}
		free(word_p);
		return (1);
	}
	return (0);
}

static int	fill_words(const char *s, char limit, char **word_p)
{
	size_t	len;
	int		position;

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == limit)
			s++;
		while (*s && *s != limit)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_allocation(word_p, position, len + 1))
				return (1);
			ft_strlcpy(word_p[position], (char *)s - len, len + 1);
		}
		position++;
	}
	return (0);
}

static size_t	count_words(char const *s, char limit)
{
	size_t	words;
	int		in_word;

	words = 0;
	while (*s)
	{
		in_word = 0;
		while (*s && *s == limit)
			s++;
		while (*s && *s != limit)
		{
			if (!in_word)
			{
				words++;
				in_word = 1;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**word_p;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	word_p = malloc(sizeof(char *) * (words + 1));
	if (!word_p)
		return (NULL);
	word_p[words] = NULL;
	if (fill_words(s, c, word_p))
		return (NULL);
	return (word_p);
}
