
#include "minishell.h"

static void	ft_chdir_path(char *path)
{
	char	*pwd;
	char	*error_msg;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	insert_in_table("OLDPWD", pwd, minis()->env); //This is not 100% correct(note to self)
	free(pwd);
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		error_msg = ft_strjoin("cd: ", path);
		error_mess(error_msg, NO_FILE_OR_DIR, 1);
		free(error_msg);
		return ;
	}
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	insert_in_table("PWD", pwd, minis()->env);
	free(pwd);
}

static void	ft_chdir_oldpwd(char *path)
{
	ft_printf("%s\n");
	ft_chdir_path(path);
}

static void	ft_chdir_home(void)
{
	char	*path;

	path = ft_strdup(hashmap_search(minis()->env, "HOME"));
	if (!path)
	{
		error_mess("cd", NO_HOME, 1);
		free(path);
		return ;
	}
	ft_chdir_path(path);
	free(path);
}

void	ft_cd(char *path)
{
	char	*current_path;

	minis()->error_status = 0;
	if ((!path) || !(ft_strcmp(path, "~")))
	{
		ft_chdir_home();
		return ;
	}
	else if (!ft_strcmp(path, "-"))
	{
		current_path = ft_strdup(hashmap_search(minis()->env, "OLDPWD"));
		if (!*current_path)
		{
			error_mess("cd", NO_OLDPWD, 1);
			free(current_path);
			return ;
		}
		ft_chdir_oldpwd(current_path);
	}
	else
	{
		current_path = ft_strdup(path);
		ft_chdir_path(current_path);
	}
	free(current_path);
}
