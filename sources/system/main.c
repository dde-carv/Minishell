
#include "minishell.h"

/* static void	start_minishell(char *line, char **env) // TODO: this is to innitialize and start important things
{
	char	**line_split;
	int		i;

	i = 0;
	line_split = ft_split(line, ' ');
} */

int	main(int ac, char **av, char **env)
{
	(void)av;
	//char **export = ft_split("", ' ');

	if (ac > 1)
		return (0);
	set_env(env);
	while (1)
	{
		set_input();
		if (!minis()->ms->line)
			break;
		//parse_input();
		if (!ft_strcmp(minis()->ms->line, "exit") && (ft_strlen(minis()->ms->line)) == 4)
			break;
		// start_minishell(...); // TODO: this is to innitialize and start important things
		ft_printf("%s\n", minis()->ms->line);
		//ft_export(export);
		free(minis()->ms->line);
	}
	exit_minishell(minis()->error_status); // * this still need some work(not final)
	//free_array(export);
	//rl_clear_history();
	free(minis()->ms->line);
	return (0);
}
