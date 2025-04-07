#include "minishell.h"

void	update_env_cd(char *pwd)
{
	if (pwd)
	{
		insert_in_table("OLDPWD", pwd, minis()->env);
		free_pointer(pwd);
		pwd = getcwd(NULL, 0);
		if (hashmap_search(minis()->env, "PWD"))
			hashmap_delete(minis()->env, "PWD");
		insert_in_table("PWD", pwd, minis()->env);
		free_pointer(pwd);
	}
}

void	ft_verify_cd(char **path, int fd)
{
	minis()->error_status = 0;
	if (array_len(path) > 1)
		return (error_mess("cd", TOO_MANY_ARGS, 1));
	else
		ft_cd(path[0], fd);
}
