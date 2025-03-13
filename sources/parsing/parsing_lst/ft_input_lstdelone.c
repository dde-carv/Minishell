#include "../../../includes/minishell.h"

void	ft_input_lstdelone(t_input **lst)
{
	t_input	*temp;

	temp = *lst;
	free_pointer(temp->cmd);
	free_pointer(temp->arg);
	free_pointer(temp->path);
	free_array(temp->args);
	free(temp);
}
