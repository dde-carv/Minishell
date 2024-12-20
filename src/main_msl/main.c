
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
	//ft_printf("PWD=%s\n", cwd);
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

static void set_env(t_minishell *ms, char **env)
{
	ms->my_env = NULL;
	if (*env)
		env_dup(ms, env); //function to duplicate env variable
	else
		env_create(ms); //function to create env variable (not complete)
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
	t_minishell	ms;

	if (ac == 1)
	{
		set_env(&ms, env);
		while (1)
		{
			ms.promp = ft_getprompt();
			ms.full_promp = ft_strjoin(ms.promp, "\033[1;33m $ \033[0m");
			free(ms.promp);
			ms.line = readline(ms.full_promp);
			free(ms.full_promp);
			if (!ms.line)
				break;
			if (ms.line)
				add_history(ms.line);
			if (!ft_strcmp(ms.line, "exit") && (ft_strlen(ms.line)) == 4)
				break;
			// start_minishell(...); //function to initialize minishell(not implemented)
			ft_printf("%s\n", ms.line);
			free (ms.line);
		}
		//ft_exitminishell(...); //function to exit minishell(not implemented)
		rl_clear_history();
		free(ms.line);
	}
	return (0);
}
