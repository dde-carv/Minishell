#include "../../includes/minishell.h"

void	expantions(char *s)
{
	int			i;
	int			c;
	char		*str;

	if (!s || !*s)
		return ;
	str = *s;
	i = -1;
	c = 0;
	while (str[++i] != 0)
	{
		if ((str[i] == '"' || str[i] == '\'') && !c)
			c = str[i];
		else if (str[i] == c)
			c = 0;
		else if (str[i] == '$' && (!c || c == '"') && str[i + 1]
			&& ft_isalpha(str[i + 1]))
			str[i] = 2;
	}
}

int	closed_quotes(char *s)
{
	int		i;
	char	in_quotes;

	i = -1;
	in_quotes = 0;
	if (!s)
		return (1);
	while (s[++i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !in_quotes)
			in_quotes = s[i];
		else if (s[i] == in_quotes)
			in_quotes = 0;
	}
	return (in_quotes == 0);
}

int	is_valid(void)
{
	t_input	*lst;

	lst = minis()->input;

	while (lst)
	{
		if (!closed_quotes(lst->cmd) || !closed_quotes(lst->arg))
		{
			perror("syntax error");
			return (0);
		}
		if (!lst->cmd || !*lst->cmd)
		{
			perror("syntax error pipe");
			return (0);
		}
		expantions(lst->cmd);
		expantions(lst->arg);
		lst = lst->next;
	}
	return (1);
}

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_lstclear(&minis()->input->cmd, ft_lstdelone);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	if (minis()->input->cmd && *minis()->input->cmd)
		execute(); 
}
