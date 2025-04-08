#include "minishell.h"

static void	start_minishell(char **env)
{
	set_env(env);
	rl_catch_signals = 1;
	minis()->signal = 1;
	load_signals();
	minis()->error_status = 0;
}

static void	handle_sigint(void)
{
	if (minis()->signal != 0)
		minis()->signal = 0;
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac > 1)
		ft_putstr_fd("Too many arguments!\n", 2);
	start_minishell(env);
	while (1)
	{
		handle_sigint();
		set_input();
		if (!*minis()->ms->line)
			continue ;
		parse_input();
		transform_input();
		ft_input_lstclear(&minis()->input);
		free_pointer(minis()->ms->line);
	}
	exit_minishell();
	return (0);
}

// make re && clear && valgrind --suppressions=readline.supp --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes ./minishell

// echo "pwd $HOME" | whoami | uname -a | echo Hello, $USER | curl --version | echo "Shell: $SHELL'" | echo "Path: $PATH, Home: '$HOME'" | echo "Hello, World!" | echo $? | echo $_
// echo "pwd $HOME" | whoami | uname -a | echo Hello, $USER | curl --version | echo "Shell: $SHELL'" | echo "Path: $PATH, Home: '$HOME'" | echo "Hello, World!" | < infile cat hello > outfile | echo $? | echo $_ > lol
// < infile cat hello | cat $_ > outfile