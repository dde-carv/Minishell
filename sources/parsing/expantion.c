#include "../../includes/minishell.h"

/* //? Don't forget to add flag for singl/double quotes (maybe this works, don't change for now only in tests)

line:	echo "My home directory is: $HOME"
output:	My home directory is: /home/dde-carv

line:	echo 'My home directory is: $HOME'
output:	My home directory is: $HOME

line:	echo "My home directory is: '$HOME'"
output:	My home directory is: '/home/dde-carv'

line:	echo 'My home directory is: "$HOME"'
output:	My home directory is: "$HOME"

line:	echo "My home directory is: '$HOME"
output:	My home directory is: '/home/dde-carv

line:	echo 'My home directory is: "$HOME'
output:	My home directory is: "$HOME

 */

void	expantions(char **s)
{
	int			i;
	int			in_quotes;
	char		*str;

	if (!s || !*s)
		return ;
	str = *s;
	i = 0;
	in_quotes = 0;
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

char	*sub_expantion(char *og, char *value)
{
	char		*new;
	int			i;
	int			j;

	new = ft_calloc(ft_strlen(og) + ft_strlen(value) + 1, sizeof(char));
	if (!new)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	while (og[i])
	{
		if (og[i] == 2)
		{
			i++;
			while (og[i] && ft_isalnum(og[i]))
				i++;
			while (*value)
				new[j++] = *value++;
			while (og[i])
				new[j++] = og[i++];
			break ;
		}
		else
			new[j++] = og[i++];
	}
	while (og[i])
		new[j++] = og[i++];
	free(og);
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

	i = 0;
	while (s[i++])
	{
		if (s[i] == 2)
		{
			j = i + 1;
			while (s[j] && ft_isalnum(s[j]) && ft_isalpha(s[i + 1]))
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
