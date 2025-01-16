#include "minishell.h"

t_global	*minis(void)
{
	static t_global	data;

	if(!data.ms)
	{
		data.ms = malloc(sizeof(t_minishell));
		if (!data.ms)
			return (NULL);
		ft_bzero(data.ms, sizeof(t_minishell));
	}
	return (&data);
}
