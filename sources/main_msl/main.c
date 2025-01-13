
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

/* 	tmp = minis()->my_env;
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
		minis()->ms->promp = ft_getprompt();
		minis()->ms->full_promp = ft_strjoin(minis()->ms->promp, "\033[1;33m $ \033[0m");
		free(minis()->ms->promp);
		minis()->ms->line = readline(minis()->ms->full_promp);
		free(minis()->ms->full_promp);
		if (!minis()->ms->line)
			break;
		if (minis()->ms->line)
			add_history(minis()->ms->line);
		if (!ft_strcmp(minis()->ms->line, "exit") && (ft_strlen(minis()->ms->line)) == 4)
			break;
		// start_minishell(...); //function to initialize minishell(not implemented)
		ft_printf("%s\n", minis()->ms->line);
		free (minis()->ms->line);
	}
	exit_minishell(0); //function to exit minishell(not implemented)
	//rl_clear_history();
	free(minis()->ms->line);
	return (0);
}
