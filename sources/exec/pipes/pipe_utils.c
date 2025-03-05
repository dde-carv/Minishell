
#include "minishell.h"

void	ft_init_pipex(t_pipe *pipex, int argc)
{
	int	i;

	i = argc;
	pipex->pids = ft_calloc(sizeof(int), (size_t)args);
	if (pipex->pids == NULL)
		return ;
	pipex->cmd_paths = ft_calloc(sizeof(char *), (size_t)argc);
	if (pipex->cmd_paths)
		return (free(pipex->pids));
	if (i > 1)
		i -= 1;
	pipex->fd = ft_calloc(sizeof(int), (size_t)i);
	if (pipex->fd == NULL)
		return (free(pipex->pids), free(pipex->cmd_paths));
}

void	ft_count_args(t_input	*input, int *argc)
{
	int		len;
	t_input	*tmp;

	len = 0;
	tmp = input;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	*argc = len;
}