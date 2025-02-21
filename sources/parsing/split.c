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
		// Skip spaces
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (0);
		words++; // Found a word
		// Move until the word ends
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
		// Skip leading spaces
		while (str[start] == ' ')
			start++;
		// Mark the end of the token
		end = end_word(str, start);
		// Extract token using a substring function
		result[word_index++] = ft_substr(str, start, end - start);
		start = end;
	}
	result[word_index] = NULL;
	return (result);
}

bool	split_need(char *s)
{
	char	in_quotes;
	int		i;

	i = 0;
	if (!s || !*s || *s != 2)
		return (false);
	in_quotes = 0;
	while (s[i++])
	{
		update_quote_state(s[i], &in_quotes);
		if (s[i] == 2 && !in_quotes)
		{
			while (ft_isalpha(s[++i]))
				;
			if (s[i] == 0 || s[i] == ' ')
				return (true);
			return (false);
		}
	}
	return (false);
}

/*

Summary:

Counting Words: Ignores extra spaces and respects quotes.

Finding Word End: Uses a helper that safely stops at a space or the end of quoted sections.

Extracting Tokens: Allocates an array and fills it with the tokens from the input string.

Special Marker Handling: The function split_need checks for markers that indicate further processing is needed.

*/
