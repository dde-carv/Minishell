
#include "minishell.h"

void	free_pointer(char *str)
{
	if (str)
		free(str);
}

void	free_array(char **array)
{
	int	i;

	if (*array)
	{
		i = -1;
		while (array[++i])
			free(array[i]);
		free(array);
	}
}
