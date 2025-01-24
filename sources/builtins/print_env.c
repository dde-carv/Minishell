
#include "minishell.h"

void	print_env(int fd)
{
	char	**env_array;

	env_array = hashmap_to_array();
	print_array_fd(env_array, fd);
	free_array(env_array);
}
