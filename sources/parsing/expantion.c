#include "../../includes/minishell.h"

void	expantions(char *s)
{
	int			i;
	int			in_quotes;
	char		*str;

	str = *s;
	i = 0;
	in_quotes = 0;
	if (!s || !*s)
		return ;
	while (str[i++])
	{
		if ((str[i] == '"' || str[i] == '\'') && !in_quotes)
			in_quotes = str[i];
		else if (str[i] == in_quotes)
			in_quotes = 0;
		else if (str[i] == '$' && (!in_quotes || in_quotes == '"')
			&& str[i + 1] && ft_isalpha(str[i + 1]))
			str[i] = 2;
	}
}

char	*sub_expantion(char *s, char *str)
{
	char		*new;
	int			i;
	int			j;

	new = ft_calloc(ft_strlen(s) + ft_strlen(str) + 1, sizeof(char));
	if (!new)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 2)
		{
			i++;
			while (s[i] && ft_isalpha(s[i]))
				i++;
			while (*str)
				new[j++] = *str++;
			while (s[i])
				new[j++] = s[i++];
			break ;
		}
		else
			new[j++] = s[i++];
	}
	while (s[i])
		new[j++] = s[i++];
	free(s);
	return (new);
}

bool	is_expantion(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == 2)
			return (1);
		str++;
	}
	return (0);
}
