
#include "minishell.h"

void	ft_clean_envvars(char **vars, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(vars[i]);
		i++;
	}
	free(vars);
}
