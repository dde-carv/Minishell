
#include "../../../includes/pipex.h"

static char	**full_argv(t_input *input)
{
	int		i;
	char	**argv;

	argv = ft_calloc(array_len(input->args) + 3, sizeof(char *));
	argv[0] = ft_strdup(input->cmd);
	i = 0;
	while (input->args[i])
	{
		argv[i + 1] = ft_strdup(input->args[i]);
		i++;
	}
	argv[i + 1] = NULL;
	return (argv);
}

void	true_execve(char *path, char **envp)
{
	char	**argv;

	argv = full_argv(minis()->input);
	if (execve(path, argv, envp))
		return (free_array((void **)argv));
}