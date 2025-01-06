
#include "minishell.h"

/* static void	pwd_create(char **env, char *cwd)
{
	env[0] = ft_calloc(sizeof(char), ft_strlen(cwd) + 5);
	if (!env[0])
	{
		ft_clean_envvars(env, 1);
		free(cwd);
		exit(1);
	}
	ft_strcpy(env[0], "PWD=");
	ft_strcat(env[0], cwd);
}

static void	shlvl_create(char **env, char *cwd) //this is wrong
{
	env[1] = ft_calloc(sizeof(char), 8);
	if (!env[1])
	{
		ft_clean_envvars(env, 2);
		free(cwd);
		exit(1);
	}
	ft_strcpy(env[1], "SHLVL=1");
}

static void	under_create(char **env, char *cwd)
{
	env[2] = ft_calloc(sizeof(char), ft_strlen(cwd) + 16);
	if (!env[2])
	{
		ft_clean_envvars(env, 3);
		free(cwd);
		exit(1);
	}
	ft_strcpy(env[2], "_=");
	ft_strcat(env[2], cwd);
	ft_strcat(env[2], "/./minishell");
}

static void	old_pwd_create(char **env, t_minishell *ms) //we still can't implement this function
{
	ms->old_pwd = NULL; //temporary
	if (!ms->old_pwd)
		return ;
	env[3] = ft_calloc(sizeof(char), ft_strlen(ms->old_pwd) + 8);
	if (!env[3])
	{
		ft_clean_envvars(env, 4);
		free(ms->old_pwd);
		exit(1);
	}
	ft_strcpy(env[3], "OLDPWD=");
	ft_strcat(env[3], ms->old_pwd);
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
		under_create(ms->my_env, cwd);
		ft_printf("%s\n", ms->my_env[2]);
		old_pwd_create(ms->my_env, ms);
		ft_printf("%s\n", ms->my_env[3]);
		free(cwd);
		ms->my_env[4] = NULL;
	}
} */
