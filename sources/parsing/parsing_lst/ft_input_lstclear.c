#include "minishell.h"

void	ft_input_lstclear(t_input **lst)
{
	t_input	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_input_lstdelone(&tmp);
		}
	}
}
