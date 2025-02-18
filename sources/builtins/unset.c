
#include "minishell.h"

void	ft_unset(char **args) //* when parsing is finished remember to create a function to select what command is going to be executed(there are some that are going to take more then one arg and need to split)
{
	int	i;

	i = 0;
	minis()->error_status = 0;
	while (args[i])
	{
		if (hashmap_search(minis()->env, args[i]))
			hashmap_delete(minis()->env, args[i]);
		else if (hashmap_search(minis()->sesion_vars, args[i]))
			hashmap_delete(minis()->sesion_vars, args[i]);
		else if (hashmap_search(minis()->non_value_vars, args[i]))
			hashmap_delete(minis()->non_value_vars, args[i]);
		i++;
	}
}
