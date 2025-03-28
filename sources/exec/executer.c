
#include "minishell.h"

static int	ret(t_input *cmd)
{
	if (!cmd)
		return (1);
	return (minis()->error_status= 1, ft_putstr_fd("Error near >", 2), 0);
}

// Verify if everything went well with redirections
static int	verify_redir(t_input **input)
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
	return (ret(tmp));
}

// Verify is command given is a builtin
int	is_builtin(char *cmd)
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

// !! Args is NULL if there is a redirections (Verify if it is only on the mac)

void	execute(void)
{
	if (!verify_redir(&minis()->input))
		return ;
	else if (ft_input_lstsize(&minis()->input) == 1 && is_builtin(minis()->input->cmd))
		ft_exec_builtin(minis()->input->cmd, minis()->input->args);
	else
		ft_exec_pipex();
}
