
#include "minishell.h"

/* static char	*get_varv(char *env, int start, int len)
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
} */

static char	*find_var_v(char *var)
{
	int		i;
	int		j;
	char	*var_v;

	i = 0;
	while (var[i] != '=')
		i++;
	j = i;
	while (var[j])
		j++;
	var_v = ft_substr(var, i + 1, j);
	return (var_v);
}

static char	*find_var_n(char *var)
{
	int		i;
	char	*var_n;

	i = 0;
	while (var[i] != '=')
		i++;
	var_n = ft_substr(var, 0, i);
	return (var_n);
}

t_hashmap	*hash_env(char **env)
{
	int			i;
	int			len;
	char		*var_n;
	char		*var_v;
	t_hashmap	*table;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	table = create_table(len * 2);
	while (i < len)
	{
		var_n = find_var_n(env[i]);
		var_v = find_var_v(env[i]);
		insert_in_table(var_n, var_v, table);
		i++;
		free(var_n);
		free(var_v);
	}
	return (table);
}
