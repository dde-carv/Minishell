
#include "minishell.h"

static void update_under(void)
{
	t_input *tmp;

	tmp = minis()->input;
	while (tmp->next)
		tmp = tmp->next;
	if (*tmp->args)
	{
		if (hashmap_search(minis()->env, "_"))
		{
			hashmap_delete(minis()->env, "_");
			insert_in_table("_", tmp->args[array_len(tmp->args) - 1], minis()->env);
		}
	}
	else
	{
		if (hashmap_search(minis()->env, "_"))
		{
			hashmap_delete(minis()->env, "_");
			insert_in_table("_", tmp->cmd, minis()->env);
		}
	}
}

static int verify_files(t_fd *fd)
{
	t_fd	*tmp;

	if (!fd)
		return (1);
	tmp = fd;
	while (tmp)
	{
		if (tmp->fd == -1)
			return (minis()->error_status = 1, 0);
		tmp = tmp->next;
	}
	return (1);
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

void	ft_exec_builtin(char *cmd, char **args, int fd)
{
	if (!(ft_strcmp(cmd, "echo\0")))
		ft_echo(args, fd);
	else if (!(ft_strcmp(cmd, "cd\0")))
		ft_verify_cd(args, fd);
	else if (!(ft_strcmp(cmd, "pwd\0")))
		ft_pwd(fd);
	else if (!(ft_strcmp(cmd, "export\0")))
		ft_export(args, fd);
	else if (!(ft_strcmp(cmd, "unset\0")))
		ft_unset(args);
	else if (!(ft_strcmp(cmd, "env\0")))
		ft_verify_env(args, fd);
	else if (!(ft_strcmp(cmd, "exit\0")))
		ft_exit(args);
}

void	execute(void)
{
	//change_cmd(&minis()->input);
	update_under();
	handle_fd(&minis()->input);
	if (ft_input_lstsize(&minis()->input) == 1 && !verify_files(minis()->input->fd))
		return ;
	else if (ft_input_lstsize(&minis()->input) == 1 && is_builtin(minis()->input->cmd))
		ft_exec_builtin(minis()->input->cmd, minis()->input->args, minis()->input->l_write);
	else
		ft_exec_pipex();
}
