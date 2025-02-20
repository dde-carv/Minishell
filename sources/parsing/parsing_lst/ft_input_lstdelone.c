#include "../../../includes/minishell.h"

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
