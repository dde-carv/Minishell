
#include "minishell.h"

static char	*ft_gethome(char *path)
{
	char	*partial_path;
	char	*full_path;

	partial_path = ft_substr(path, 1, ft_strlen(path));
	full_path = ft_strjoin(hashmap_search(minis()->env, "HOME"), partial_path);
	free(partial_path);
	ft_printf("%s\n", full_path);
	return (full_path);
}

static void	ft_chdir_path(char *path)
{
	char	*pwd;
	char	*final_path;
	char	*error_msg;

	if (!*path)
		return ;
	pwd = getcwd(NULL, 0);
	if (hashmap_search(minis()->env, "OLDPWD"))
		hashmap_delete(minis()->env, "OLDPWD");
	insert_in_table("OLDPWD", pwd, minis()->env);
	free(pwd);
	final_path = ft_strdup(path);
	if((!ft_strncmp(path, "~", 1)))
	{
		free(final_path);
		final_path = ft_gethome(path);
	}
	if (chdir(final_path) != 0)
	{
		error_msg = ft_strjoin("cd: ", path);
		error_mess(error_msg, NO_FILE_OR_DIR, 1);
		free(error_msg);
		free(final_path);
		return ;
	}
	pwd = NULL;
	pwd = getcwd(NULL, 0);
	insert_in_table("PWD", pwd, minis()->env);
	free(pwd);
	free(final_path);
}

static void	ft_chdir_oldpwd(char *path)
{
	ft_printf("%s\n", path);
	if (*path)
		ft_chdir_path(path);
}

static void	ft_chdir_home(void)
{
	char	*path;

	path = NULL;
	if (hashmap_search(minis()->env, "HOME"))
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

	if ((!path) || !(ft_strcmp(path, "~")))
	{
		ft_chdir_home();
		return ;
	}
	else if (!ft_strcmp(path, "-"))
	{
		if (!hashmap_search(minis()->env, "OLDPWD"))
		{
			error_mess("cd", NO_OLDPWD, 1);
			return ;
		}
		current_path = ft_strdup(hashmap_search(minis()->env, "OLDPWD"));
		ft_chdir_oldpwd(current_path);
	}
	else
	{
		current_path = ft_strdup(path);
		ft_chdir_path(current_path);
	}
	free(current_path);
}

void	ft_verify_cd(char **path) // protect to if file is put to trash
{
	minis()->error_status = 0;
	if (array_len(path) >= 1)
	{
		error_mess("cd", TOO_MANY_ARGS, 1);
		return ;
	}
	else
		ft_cd(path[0]);
}
