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

void print_fds(t_fd *fd)
{
	while (fd)
	{
		ft_printf("\nFile: %s, FD: %d, Type: %d\n", fd->file_n, fd->fd, fd->type);
		fd = fd->next;
	}
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
		return (0);
	set_env(env);

	load_signals();
	minis()->error_status = 0;
	while (1)
	{
		handle_sigint();
		set_input();
		if (!*minis()->ms->line)
			continue ;

		parse_input();
		transform_input();
		
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

// make re && clear && valgrind --suppressions=readline.supp --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes ./minishell

// echo "pwd $HOME" | whoami | uname -a | echo Hello, $USER | curl --version | echo "Shell: $SHELL'" | echo "Path: $PATH, Home: '$HOME'" | echo "Hello, World!" | echo $? | echo $_
// echo "pwd $HOME" | whoami | uname -a | echo Hello, $USER | curl --version | echo "Shell: $SHELL'" | echo "Path: $PATH, Home: '$HOME'" | echo "Hello, World!" | < infile cat hello > outfile | echo $? | echo $_ > lol
// < infile echo hello > outfile world | echo $_ > outfile