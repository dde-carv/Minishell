
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

	char **env1 = ft_split("", ' ');
	char **export1 = ft_split("", ' ');

	char **sesh_vars = ft_split("xyz=wow lol=abc", ' ');

	char **export2 = ft_split("export=MACHO SHLVL=PUNHETA", ' ');
	char **export3 = ft_split("abc lol", ' ');


	if (ac > 1)
		return (0);
	set_env(env);
	while (1)
	{
		set_input();
		if (!minis()->ms->line)
			break;


/* 		parse_input();

		t_input *current_input = minis()->input;
		if (current_input)
		{
			ft_printf("Parsed Commands:\n");
			while (current_input)
			{
				ft_printf("Command: %s, Argument: %s\n", current_input->cmd, current_input->arg);
				current_input = current_input->next;
			}
		}
		else
			ft_printf("Input line is empty.\n"); */

		if (!ft_strcmp(minis()->ms->line, "exit") && (ft_strlen(minis()->ms->line)) == 4)
			break;

		ft_printf("\n*************************    0    *************************\n");
		ft_printf("\n");
		ft_exec("env", env1);
		ft_printf("\n");
		ft_exec("export", export1);

		ft_printf("\n*************************    1    *************************\n");
		ft_exec("abc=lol", sesh_vars);
		ft_printf("\n");
		ft_exec("env", env1);
		ft_printf("\n");
		ft_exec("export", export1);

		ft_printf("\n*************************    2    *************************\n");
		ft_exec("export", export2);
		ft_printf("\n");
		ft_exec("env", env1);
		ft_printf("\n");
		ft_exec("export", export1);

		ft_printf("\n*************************    3    *************************\n");
		ft_exec("export", export3);
		ft_printf("\n");
		ft_exec("env", env1);
		ft_printf("\n");
		ft_exec("export", export1);
		ft_printf("\n");


		// start_minishell(...); // TODO: this is to innitialize and start important things
		ft_printf("%s\n", minis()->ms->line);
		free(minis()->ms->line);
	}

	free_array(env1);
	free_array(export1);
	free_array(sesh_vars);
	free_array(export2);
	free_array(export3);

	exit_minishell(); // * this still need some work(not final)
	return (0);
}

// valgrind --suppressions=readline.supp --show-leak-kinds=all --leak-check=full --track-origins=yes ./minishell
