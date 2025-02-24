#include "minishell.h"

// Count how many words (tokens) there will be
static int	words_count(char *str)
{
	char	in_quotes;
	int		words;
	int		i;

	in_quotes = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (0);
		words++; // Found a word
		while (str[i] && ((str[i] != ' ' && !in_quotes) || (in_quotes)))
		{
			update_quote_state(str[i], &in_quotes);
			i++;
		}
	}
	return (words);
}

// Find where the current word (token) ends
static int	end_word(char *str, int start)
{
	char	in_quotes;
	int		i;

	if (!str || !*str)
		return (0);
	i = start;
	in_quotes = 0;
	while (str[i])
	{
		if (str[i] == ' ' && !in_quotes)
			break ;
		update_quote_state(str[i], &in_quotes);
		i++;
	}
	return (i);
}

// Create an array of tokens
char	**split_value(char *str)
{
	char	**result;
	int		word_index;
	int		words;
	int		start;
	int		end;

	words = words_count(str);
	result = ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	word_index = 0;
	start = 0;
	while (word_index < words)
	{
		while (str[start] == ' ')
			start++;
		end = end_word(str, start); // Mark the end of the token
		result[word_index++] = ft_substr(str, start, end - start); // Extract token using a substring function
		start = end;
	}
	result[word_index] = NULL;
	return (result);
}
