#include "minishell.h"

int	ft_input_lstsize(t_input **lst)
{
	int		i;
	t_input	*tmp;

	if (!lst || !*lst)
		return (0);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return(i);
}
