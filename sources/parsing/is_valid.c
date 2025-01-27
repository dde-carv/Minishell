#include "../../includes/minishell.h"

int	is_valid(void)
{
	t_input	*lst;

	lst = minis()->input;

	while (lst)
	{
		if (!closed_quotes(lst->cmd) || !closed_quotes(lst->arg))
		{
			
		}
	}
}