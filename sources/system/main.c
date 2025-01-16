
#include "minishell.h"

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
		set_input();
		if (!minis()->ms->line)
			break;
		if (!ft_strcmp(minis()->ms->line, "exit") && (ft_strlen(minis()->ms->line)) == 4)
			break;
		// start_minishell(...); //function to initialize minishell(not implemented)
		ft_printf("%s\n", minis()->ms->line);
		free (minis()->ms->line);
		ft_cd("..");
	}
	exit_minishell(0); //function to exit minishell(not implemented)
	//rl_clear_history();
	free(minis()->ms->line);
	return (0);
}
