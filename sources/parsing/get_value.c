#include "minishell.h"

static char	*lookup_var_value(char *var_name)
{
	char	*value;

	value = NULL;
	if (hashmap_search(minis()->env, var_name))
		value = hashmap_search(minis()->env, var_name);
	return (value);
}

char	*get_value(char *s)
{
	int			i;
	int			j;
	int			len;
	char		*var_name;
	char		*value;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 2)
		{
			if (s[i + 1] == '?')
				return ("");
			j = i + 1;
			while (s[j] && ft_isalnum(s[j])
				&& (ft_isalpha(s[i + 1]) || s[i + 1] == '?'))
				j++;
			len = j - i - 1;
			var_name = ft_substr(s, i + 1, len);
			value = lookup_var_value(var_name);
			free(var_name);
			return (value);
		}
	}
	return ("");
}

/* char	*get_value(char *s)
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
			while (s[j] && (ft_isalnum(s[j]))
				&& (ft_isalpha(s[i + 1]) || s[i + 1] == '?'))
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
} */
