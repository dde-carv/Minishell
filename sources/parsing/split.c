#include "../../includes/minishell.h"

static int	words_count(t_string str)
{
	char	c;
	int		i;
	int		words;

	i = 0;
	words = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (0);
		words++;
		while (str[i] && ((str[i] != ' ' && !c) || (c)))
		{
			if ((str[i] == '\'' || str[i] == '"') && !c)
				c = str[i];
			else if (str[i] == c)
				c = 0;
			i++;
		}
	}
	return (words);
}

static int	end_word(t_string str, int s)
{
	int	i;
	int	c;

	i = s;
	if (!str || !*str)
		return (0);
	c = 0;
	while (str[i])
	{
		if (str[i] == ' ' && !c)
			break ;
		if ((str[i] == '\'' || str[i] == '"') && !c)
			c = str[i];
		else if (str[i] == c)
			c = 0;
		i++;
	}
	return (i);
}

t_string	*split_value(t_string str)
{
	t_string	*result;
	int			words;
	int			i;
	int			start[2];

	words = words_count(str);
	result = ft_calloc(words_count(str) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = -1;
	start[0] = 0;
	while (++i < words)
	{
		while (str[start[0]] == ' ')
			start[0]++;
		start[1] = end_word(str, start[0]);
		result[i] = ft_substr(str, start[0], start[1] - start[0]);
		start[0] = start[1];
	}
	result[i] = NULL;
	return (result);
}

bool	split_need(t_string s)
{
	int	i;
	int	c;

	i = -1;
	if (!s || !*s || *s != 2)
		return (false);
	c = 0;
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !c)
			c = s[i];
		else if (s[i] == c)
			c = 0;
		else if (s[i] == 2 && !c)
		{
			while (ft_isalpha(s[++i]))
				;
			if (s[i] != 0 && s[i] != ' ')
				return (false);
			return (true);
		}
	}
	return (false);
}