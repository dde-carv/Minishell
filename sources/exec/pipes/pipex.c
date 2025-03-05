
#include "minishell.h"



void	ft_exec_pipex(void)
{
	t_pipe	pipex;

	pipex = (t_pipe){0};
	ft_count_args(minis()->input, &pipex.argc);
	ft_init_pipex(&pipex, pipex.argc);
	pipex.envp = hashmap_to_array();
	pipex.env_paths = ft_split(hashmap_search(minis()->env, "PATH"), ':');
	pipex.heredoc_pid = -1;
	
}