#include "minishell.h"
// TODO: this is to innitialize and start important things
// ** take paths for pipexinside "Path"
/* static void	start_minishell(char *line, char **env)
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

	// Disable readline's own signal handlers.
	//rl_catch_signals = 0;
	// Install our own handlers once.
	load_signals();
	minis()->error_status = 0;
	while (1)
	{
		set_input();

		if (!*minis()->ms->line)
			continue ;

		parse_input();	// !! Fazer review do parsing pq no echo se os meus argumentos forem "$HOME $lol $SHLVL" ou seja uma variavel valida e uma nao valida, o meu array e null quando devia ter as expansoes das variaveis validas
						// !! Outra cena temos leaks no parse quando fazemos expansoes de variaveis que nao existem
		// Reset input for the transform test
		//ft_printf("\n=== Test transform ===\n");

		//ft_printf("\nBefore transform:\n");
		//t_input	*current_input = minis()->input;
		//while (current_input)
		//{
		//	ft_printf("Command: %s, Argument: %s\n",
		//		current_input->cmd, current_input->arg);
		//	current_input = current_input->next;
		//}

		transform_str();

		// Print the cleaned commands for verification
		//ft_printf("\nAfter transform:\n");

		//current_input = minis()->input;
		//while (current_input)
		//{
		//	ft_printf("Cleaned Command: %s, Cleaned Argument: %s\n",
		//		current_input->cmd, current_input->arg);
		//	current_input = current_input->next;
		//}

		//if (!ft_strcmp(minis()->ms->line, "exit")
		//	&& (ft_strlen(minis()->ms->line)) == 4)
		//	break;

		//ft_printf("\n=== exec built ===\n");
		// start_minishell(...); // TODO: this is to innitialize and start important things
		//ft_printf("%s\n", minis()->ms->line);
		ft_input_lstclear(&minis()->input);
		//free(current_input);
		free_pointer(minis()->ms->line);
	}
	exit_minishell(); // * this still need some work(not final)
	return (0);
}

// valgrind --suppressions=readline.supp --show-leak-kinds=all --leak-check=full --track-origins=yes ./minishell


/* echo "pwd $HOME" | whoami | uname -a | echo Hello, $USER | curl --version | echo "Shell: $SHELL'" | echo "Path: $PATH, Home: '$HOME'" | echo "Hello, World!" | echo $? */