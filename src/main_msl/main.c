
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
		ms.my_env = NULL;
		if (*env)
			env_dup(&ms, env); //function to duplicate env variable (not implemented)
		else
			env_create(&ms); //function to create env variable (not implemented)
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
			if (!ft_strncmp(ms.line, "exit", 4) && (ft_strlen(ms.line)) == 4)
			{
				write(1, "exit\n", 5);
				//ft_exitminishell(...); //function to exit minishell(not implemented)
				break;
			}
			// start_minishell(...); //function to initialize minishell(not implemented)
			ft_printf("%s\n", ms.line);
			free (ms.line);
		}
		//rl_clear_history();
		free(ms.line);
	}
	return (0);
}
