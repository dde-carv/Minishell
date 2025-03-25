
#include "minishell.h"

void	ft_echo(char **args) // !! Carrega todos os args numa string e manda para um ft_putstr_fd
{
	int	i;
	int	new_flag;

	i = 0;
	new_flag = 1;
	if (!ft_strcmp(args[i], "-n"))
	{
		new_flag = 0;
		i++;
	}
	while (args && args[i])
	{
		if (args[i + 1])
		{
			//ft_printf("%s ", args[i]);
			ft_putstr_fd(args[i], minis()->input->l_write);
			ft_putstr_fd(" ", minis()->input->l_write);
		}
		else
			ft_putstr_fd(args[i], minis()->input->l_write);
		i++;
	}
	if (new_flag)
	ft_putstr_fd("\n", minis()->input->l_write);
	minis()->error_status = 0;
}
