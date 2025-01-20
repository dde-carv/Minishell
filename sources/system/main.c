
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
	char **args = ft_split("OLDPWD     PWD   	   PATH SHLVL", ' ');

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
		// start_minishell(...); // TODO: this is to innitialize and start important things
		ft_printf("%s\n", minis()->ms->line);
		hashmap_print_table(minis()->env);
		ft_unset(args);
		while (*args)
		{
			ft_printf("Removed: %s", *args);
			args++;
		}
		hashmap_print_table(minis()->env);
		free(minis()->ms->line);
	}
	exit_minishell(minis()->error_status); // * this still need some work(not final)
	//rl_clear_history();
	free(minis()->ms->line);
	return (0);
}
