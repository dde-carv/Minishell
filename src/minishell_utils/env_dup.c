
#include "minishell.h"

//This function counts the number of variables in the environment
/* static int	var_count(char **vars)
{
	int	i;

	i = 0;
	while (vars[i])
		i++;
	return (i);
}

static void	ft_shlvlup(char *my_env)
{

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
		if (!ft_strncmp(env[i], "SHLVL=", 6))
		{
			//ft_shlvlup(ms->my_env[i]);
			ft_printf("%s\n", ms->my_env[i]);
		}
		if (!ms->my_env[i])
		{
			ft_clean_envvars(ms->my_env, i);
			exit(1);
		}
		i++;
	}
	ms->my_env[i] = NULL;
} */

void	env_dup(char **env)
{
	int	i;
	int	j;
	int	varn_len; //variable name length
	int	varv_len; //variable value length

	i = 0;
	while (env[i])
	{
		j = 0;
		varn_len = 1;
		varv_len = 0;
		while (env[i][j] != '=')
		{
			varn_len++;
			j++;
		}
		while (env[i][j])
		{
			varv_len++;
			j++;
		}
		create_var(get_varn(env[i], varn_len), get_varv(env[i], varn_len, varv_len), YES_MALL);
		i++;
	}
}
