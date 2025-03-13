
#include "minishell.h"

// Verify if everything went well with redirections
/* static int	verify_redir(t_input **input)
{
	t_input	*tmp;

	tmp = *input;
	while (tmp)
	{
		if (tmp->fd)
		{
			if (!handle_fd(&tmp))
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
} */

// Verify is command given is a builtin
static int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo\0") || !ft_strcmp(cmd, "cd\0") || !ft_strcmp(cmd, "pwd\0") || \
		!ft_strcmp(cmd, "export\0") || !ft_strcmp(cmd, "unset\0") || !ft_strcmp(cmd, "env\0") || \
		!ft_strcmp(cmd, "exit\0"))
		return (1);
	return (0);
}

void	ft_exec_builtin(char *cmd, char **args)
{
	if (!(ft_strcmp(cmd, "echo\0")))
		ft_echo(args);
	else if (!(ft_strcmp(cmd, "cd\0")))
		ft_verify_cd(args);
	else if (!(ft_strcmp(cmd, "pwd\0")))
		ft_pwd();
	else if (!(ft_strcmp(cmd, "export\0")))
		ft_export(args);
	else if (!(ft_strcmp(cmd, "unset\0")))
		ft_unset(args);
	else if (!(ft_strcmp(cmd, "env\0")))
		ft_verify_env(args);
	else if (!(ft_strcmp(cmd, "exit\0")))
		ft_exit(args);
}

void	execute(void)
{
	/* if (!verify_redir(&minis()->input))
		return ; */
	if (ft_input_lstsize(&minis()->input) == 1 && is_builtin(minis()->input->cmd))
		ft_exec_builtin(minis()->input->cmd, minis()->input->args);
	else
		ft_exec_pipex(&minis()->input);					// TODO
}
