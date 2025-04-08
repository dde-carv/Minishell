/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:59 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:00 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	execute_pipes(t_pipe *pipex, t_input *input)
{
	int		i;
	int		j;
	t_input	*tmp;

	if (pipex->argc == 1)
		return (exec_one(pipex, input));
	start_first(pipex, input);
	tmp = input;
	i = 0;
	j = pipex->argc - 1;
	while (++i < j && tmp)
	{
		tmp = tmp->next;
		if (pipe(pipex->fds[i].fd) < 0)
			return (ft_printf("Fail pipe creation(2)"), (void)pipex);
		start_rest(pipex, tmp, pipex->cmd_paths[i], i);
	}
	rest_children(pipex, pipex->last_path, input);
}

void	init_pipex(t_pipe *pipex)
{
	int	i;

	minis()->signal = 3;
	load_signals();
	pipex->env = hashmap_to_array();
	pipex->env_paths = ft_get_env_paths();
	pipex->argc = ft_input_lstsize(&minis()->input);
	pipex->pids = ft_calloc(sizeof(size_t), pipex->argc);
	if (!pipex->pids)
		return ;
	pipex->cmd_paths = ft_calloc(sizeof(char *), pipex->argc);
	if (!pipex->cmd_paths)
		return (free(pipex->pids));
	i = pipex->argc;
	if (i > 1)
		i -= 1;
	pipex->fds = ft_calloc(sizeof(t_fds), i);
	if (!pipex->fds)
		return (free(pipex->pids), free(pipex->cmd_paths));
	get_cmd_path(pipex, minis()->input);
}

int	check_valid(t_input *input, char *cmd_path)
{
	if (!is_builtin(input->cmd) && access(cmd_path, F_OK) != 0)
		return (error_mess(input->cmd, NOT_FOUND, 127), 0);
	if (!good_files(input) || !*(input->cmd))
		return (0);
	return (1);
}

int	good_files(t_input *cmd)
{
	t_fd	*f;

	f = cmd->fd;
	while (f)
	{
		if (f->fd == -1)
			return (0);
		f = f->next;
	}
	return (1);
}
