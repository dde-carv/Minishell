
#include "minishell.h"

void	ft_unset(char **args)
{
	int	i;

	i = 0;
	minis()->error_status = 0;
	while (args[i])
	{
		if (hashmap_search(minis()->env, args[i]))
			hashmap_delete(minis()->env, args[i]);
		else if (hashmap_search(minis()->non_value_vars, args[i]))
			hashmap_delete(minis()->non_value_vars, args[i]);
		i++;
	}
}
