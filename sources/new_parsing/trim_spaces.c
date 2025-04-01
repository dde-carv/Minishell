/* #include "minishell.h"

void	trim_spaces(char **s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i] = 0;
}

void	trim_front_spaces(char **s)
{
	int		i;
	char	*str;

	i = -1;
	while ((*s)[++i] == ' ')
		;
	str = ft_substr(*s, i, ft_strlen(*s) - i);
	free(*s);
	*s = str;
}
 */