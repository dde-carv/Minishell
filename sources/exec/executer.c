
#include "minishell.h"

// ! don't forget to add flag if arg is command with args for example abc="cd .." and
// !   if we execute $abc IT WILL EXECUTE

void	ft_exec(char *cmd, char **args)
{
	if (ft_strchr(cmd, '='))				// ! create flag if expansion is calling another variable to not create it and send it to execute_cmd(pipex)
		ft_sesh_vars(cmd, args);
	else if (!(ft_strcmp(cmd, "echo\0")))
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
	/* else
		ft_exec_cmd(cmd, args); */					// TODO
}
