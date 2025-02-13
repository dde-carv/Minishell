#include "../../includes/minishell.h"

void	take_quotes(char **str)
{
	char	*s;
	int		i;
	int		j;
	int		in_quotes;

	s = *str;
	i = 0;
	j = 0;
	in_quotes = 0;
	while (s[i++])
	{
		if ((s[i] == '"' || s[i] == '\'') && !in_quotes)
			in_quotes = s[i];
		else if (s[i] == in_quotes)
			in_quotes = 0;
		else
			(*str)[j++] = s[i];
	}
	while (j < i)
		(*str)[j++] = 0;
}
