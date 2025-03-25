
#include "minishell.h"

static void	print_env(int fd)
{
	char	**env_array;

	env_array = hashmap_to_array();
	print_array_fd(env_array, fd);
	free_array((void **)env_array);
}

void	ft_verify_env(char **args)
{
	minis()->error_status = 0;
	if (args[0])
		return (error_mess("env: ", TOO_MANY_ARGS, 1));
	else
		print_env(minis()->input->l_write);
}