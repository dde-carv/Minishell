
#include "minishell.h"

//function to get the prompt using env variable
static char	*ft_getprompt(void)
{
	int		i;
	char	**promp;
	char	*cwd;
	char	*last;

	i = 0;
	promp = NULL;
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	promp = ft_split(cwd, '/');
	free(cwd);
	i = 0;
	while (promp[i])
		i++;
	last = ft_strdup(promp[i - 1]);
	i = 0;
	while (promp[i])
	{
		free(promp[i]);
		i++;
	}
	free(promp);
	return (last);
}

static void set_env(char **env)
{
//	t_env	*tmp;


	if (*env)
		env_dup(env); //function to duplicate env variable
	else
		env_create(); //function to create env variable

/* 	tmp = minishell()->my_env;
	while (tmp->next)
	{
		ft_printf("%s=%s\n", tmp->var_n, tmp->var_v);
		tmp = tmp->next;
	} */
}

/* static void	start_minishell(char *line, char **env) //function to initialize pipex
{
	char	**line_split;
	int		i;

	i = 0;
	line_split = ft_split(line, ' ');
} */

int	main(int ac, char **av, char **env)
{
	(void)av;

	if (ac > 1)
		return (0);
	set_env(env);
	while (1)
	{
		minishell()->ms->promp = ft_getprompt();
		minishell()->ms->full_promp = ft_strjoin(minishell()->ms->promp, "\033[1;33m $ \033[0m");
		free(minishell()->ms->promp);
		minishell()->ms->line = readline(minishell()->ms->full_promp);
		free(minishell()->ms->full_promp);
		if (!minishell()->ms->line)
			break;
		if (minishell()->ms->line)
			add_history(minishell()->ms->line);
		if (!ft_strcmp(minishell()->ms->line, "exit") && (ft_strlen(minishell()->ms->line)) == 4)
			break;
		// start_minishell(...); //function to initialize minishell(not implemented)
		ft_printf("%s\n", minishell()->ms->line);
		free (minishell()->ms->line);
	}
	exit_minishell(0); //function to exit minishell(not implemented)
	//rl_clear_history();
	free(minishell()->ms->line);
	return (0);
}
