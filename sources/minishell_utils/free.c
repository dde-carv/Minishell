
#include "minishell.h"

void	free_pointer(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_array(char **array)
{
	int	i;

	if (array)
	{
		i = -1;
		if (array[0])
		{
			while (array[++i])
				free_pointer(array[i]);
		}
		free(array);
		array = NULL;
	}
}
