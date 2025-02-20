
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
			if (!handle_fd(&tmp)) // TODO
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
		print_env(1);
	else if (!(ft_strcmp(cmd, "exit\0")))
		ft_exit(args);
}

void	execute(void)
{
	/* if (!verify_redir(&minis()->input))
		return ; */
	if (ft_input_lstsize(&minis()->input) == 1 && ft_strchr(minis()->input->cmd, '=') /* && !skip_to_exec_cmd*/)				// ! create flag if expansion is calling another variable to not create it and send it to execute_cmd(pipex)
		ft_sesh_vars(minis()->input->cmd, minis()->input->args);
	else if (ft_input_lstsize(&minis()->input) == 1 && is_builtin(minis()->input->cmd))
		ft_exec_builtin(minis()->input->cmd, minis()->input->args);
	/* else
		ft_exec_cmd(cmd, args); */					// TODO
}
