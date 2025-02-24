
#include "minishell.h"

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

t_hashmap	*create_hash_env(void)
{
	char		*pwd;
	t_hashmap	*table;

	pwd = getcwd(NULL, 0);
	table = create_table(200);
	insert_in_table("PATH", "/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:.", table); // !! verify if this is the correct path for "env -i" (In the school computers)
	insert_in_table("PWD", pwd, table);
	insert_in_table("SHLVL", "1", table);
	insert_in_table("_", "/usr/bin/env", table);
	free(pwd);
	return (table);
}

void	set_env(char **env)
{
	(void)env;
	if (*env)
	{
		minis()->env = hash_env(env);
		shlvl_update();
	}
	else
		minis()->env = create_hash_env();
	minis()->non_value_vars = create_table(100);
	minis()->sesion_vars = create_table(100);
	minis()->table = create_table(100);
}
