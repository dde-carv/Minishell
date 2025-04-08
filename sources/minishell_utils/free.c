#include "minishell.h"

void	free_pointer(void *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_array(void **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free_pointer(array[i]);
	free(array);
	array = NULL;
}
