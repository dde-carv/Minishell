#include "../../includes/minishell.h"

unsigned long	hash_function(const char *key, unsigned int size)
{
	unsigned long	hash_value;
	unsigned int	i;

	hash_value = 0;
	i = 0;
	while (i < size && key[i])
	{
		hash_value = ((hash_value << 5) + hash_value) + key[i];
		i++;
	}
	return (hash_value % size);
}
