#include "../../includes/minishell.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i++])
		free(args[i]);
	free(args);
}
