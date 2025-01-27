
#include "minishell.h"

void	ft_echo(char **args)
{
	int	i;
	int	new_flag;

	i = 0;
	new_flag = 1;
	if (args[i + 1] && !ft_strcmp(args[i], "-n"))
	{
		new_flag = 0;
		i++;
	}
	while (args && args[i])
	{
		if (args[i + 1])
			ft_printf("%s ", args[i]);
		else
			ft_printf("%s", args[i]);
		i++;
	}
	if (new_flag)
		ft_printf("\n");
}
