
#include "minishell.h"

static void	pwd_create(char **env, char *cwd)
{
	env[0] = ft_calloc(sizeof(char), ft_strlen(cwd) + 5);
	if (!env[0])
	{
		ft_clean_envvars(env, 1);
		free(cwd);
		exit(1);
	}
	ft_strlcpy(env[0], "PWD=", 5);
	ft_strlcat(env[0], cwd, ft_strlen(cwd) + 5);
}

static void	shlvl_create(char **env, char *cwd)
{
	env[1] = ft_calloc(sizeof(char), 8);
	if (!env[1])
	{
		ft_clean_envvars(env, 2);
		free(cwd);
		exit(1);
	}
	ft_strlcpy(env[1], "SHLVL=1", 8);
}



void	env_create(t_minishell *ms)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ms->my_env = ft_calloc(sizeof(char *), 5);
		if (!ms->my_env)
		{
			free(ms->my_env);
			free(cwd);
			exit(1);
		}
		pwd_create(ms->my_env, cwd);
		ft_printf("%s\n", ms->my_env[0]);
		shlvl_create(ms->my_env, cwd);
		ft_printf("%s\n", ms->my_env[1]);
		//under_create(ms->my_env, cwd); //we still can't implement this function
		//old_pwd_create(ms->my_env, cwd);
		free(cwd);
		ms->my_env[4] = NULL;
	}
}
