
#include "minishell.h"

void	free_pointer(void *str)
{
	if (str)
	{
		//printf("Freeing pointer: %p\n", str);
		free(str);
		str = NULL;
	}
}

void	free_array(void **array)
{
	int	i;

	if (array)
	{
		//printf("Freeing array: %p\n", array);
		i = -1;
		if (array[0])
		{
			while (array[++i])
			{
				//printf("Freeing array element: %p\n", array[i]);
				free_pointer(array[i]);
				array[i] = NULL;
			}
		}
		free(array);
		array = NULL;
	}
}
