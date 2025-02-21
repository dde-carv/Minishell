#include "minishell.h"

void	expantions(char **s)
{
	char		in_quotes;
	char		*str;
	int			i;

	if (!s || !*s)
		return ;
	str = *s;
	i = -1;
	in_quotes = 0;
	while (str[++i])
	{
		update_quote_state(str[i], &in_quotes);
		if (str[i] == '$' && (!in_quotes || in_quotes == '"')
			&& str[i + 1] && (ft_isalpha(str[i + 1]) || str[i + 1] == '?'))
			str[i] = 2;
	}
}

char	*sub_expantion(char *str, char *value)
{
	char		*error_str;
	char		*new;
	int			i;
	int			j;
	int			k;

	if (value == NULL)
		return (ft_strdup(""));
	new = ft_calloc(ft_strlen(str) + ft_strlen(value) + 1, sizeof(char));
	if (!new)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 2)
		{
			i++;
			if (str[i] == '?')
			{
				error_str = ft_itoa(minis()->error_status);
				k = 0;
				while (error_str[k])
					new[j++] = error_str[k++];
				free(error_str);
				i++;
			}
			else
			{
				while (str[i] && (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?')) //! check if there is more special characters
					i++;
				while (*value)
					new[j++] = *value++;
			}
			while (str[i])
				new[j++] = str[i++];
			break ;
		}
		else
			new[j++] = str[i++];
	}
	while (str[i])
		new[j++] = str[i++];
	free(str);
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

char	*get_value(char *s)
{
	int			i;
	int			j;
	int			len;
	char		*str;
	char		*value;

	i = -1;
	value = NULL;
	while (s[++i])
	{
		if (s[i] == 2)
		{
			if (s[i + 1] == '?')
				return ("");
			j = i + 1;
			while (s[j] && (ft_isalnum(s[j])) && (ft_isalpha(s[i + 1]) || s[i + 1] == '?'))
				j++;
			len = (j - i - 1);
			str = ft_substr(s, (i + 1), len);
			if (hashmap_search(minis()->env, str))
				value = hashmap_search(minis()->env, str);
			else if (hashmap_search(minis()->sesion_vars, str))
				value = hashmap_search(minis()->sesion_vars, str);
			free(str);
			return (value);
		}
	}
	return ("");
}
