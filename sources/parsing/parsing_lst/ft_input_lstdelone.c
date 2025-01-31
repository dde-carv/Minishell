#include "../../../includes/minishell.h"

static void	free_args(char **s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_input_lstdelone(t_input **lst)
{
	t_input	*temp;

	temp = *lst;
	if (temp->arg)
		free(temp->arg);
	if (temp->cmd)
		free(temp->cmd);
	free_args(temp->args);
	free(temp);
}
