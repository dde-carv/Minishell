
#include "minishell.h"

//This function counts the number of variables in the environment
static int	var_count(char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
		i++;
	return (i);
}

void	env_dup(t_minishell *ms, char **env)
{
	int	i;

	i = 0;
	ms->my_env = ft_calloc(sizeof(char *), (var_count(env) + 1));
	if (!ms->my_env)
	{
		free(ms->my_env);
		exit(1);
	}
	while (env[i])
	{
		ms->my_env[i] = ft_strdup(env[i]);
		if (!ms->my_env[i])
		{
			ft_clean_envvars(ms->my_env, i);
			exit(1);
		}
		i++;
	}
	ms->my_env[i] = NULL;
}
