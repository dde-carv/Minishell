
#include "minishell.h"

char	**hashmap_to_array(void)
{
	unsigned int	i;
	unsigned int	j;
	t_entry			*current;
	t_entry			*tmp;
	char			**env;

	i = 0;
	j = 0;
	env = (char **)ft_calloc(sizeof (char *), minis()->env->count + 1);
	while (i < minis()->env->size && j < minis()->env->count)
	{
		current = minis()->env->entries[i];
		while (current)
		{
			tmp = current->next;
			env[j] = ft_strjoin_var(3, current->key, "=", current->value);
			current = tmp;
			j++;
		}
		i++;
	}
	return(env);
}

void	print_env(int fd)
{
	char	**env_array;

	env_array = hashmap_to_array();
	print_array_fd(env_array, fd);
	free_array(env_array);
}
