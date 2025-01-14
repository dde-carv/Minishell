
#include "minishell.h"

static char	*get_varv(char *env, int start, int len)
{
	char	*val;

	val = malloc(sizeof(char) * len + 1);
	if (!val)
		error_mag(MALL_ERROR);
	ft_strcpy(val, env + start);
	return (val);
}

static char	*get_varn(char *env, int len)
{
	char	*name;

	name = malloc(sizeof(char) * len + 1);
	if (!name)
		error_mag(MALL_ERROR);
	ft_strlcpy(name, env, len);
	return (name);
}

void	env_dup(char **env)
{
	int	i;
	int	j;
	int	varn_len;
	int	varv_len;

	i = -1;
	while (env[++i])
	{
		j = -1;
		varn_len = 1;
		varv_len = 0;
		while (env[i][++j] != '=')
			varn_len++;
		while (env[i][++j])
			varv_len++;
		create_var(get_varn(env[i], varn_len), get_varv(env[i], varn_len, varv_len), YES_MALL);
	}
}
