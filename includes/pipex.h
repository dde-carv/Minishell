/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:17:11 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:17:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "minishell.h"
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

# define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

typedef struct s_fds
{
	int			fd[2];
}		t_fds;

typedef struct s_pipe
{
	t_fds		*fds;
	size_t		argc;
	int			*pids;
	int			flag;
	char		*last_path;
	char		**env;
	char		**cmd_paths;
	char		**env_paths;
}		t_pipe;

char	*ft_check_path(char *cmd, char **paths);
void	exit_pipex(t_pipe *pipex);
void	get_cmd_path(t_pipe *pipex, t_input *input);
char	**ft_get_env_paths(void);
void	ft_exec_pipex(void);
void	get_fds(t_input *input, char *cmd_path);
void	fd_close(t_pipe *pipex);
void	ft_close(int fd);
void	close_one_fd(t_pipe *pipex);
void	pos_execute(t_pipe *pipex);
void	fd_close_all(t_input *input);
void	close_fd(t_input *input);
void	true_execve(char *path, t_input *input, char **envp);
int		check_for_hd(t_input *input);
void	start_rest(t_pipe *pipex, t_input *input, char *cmd_path, int i);
void	start_first(t_pipe *pipex, t_input *input);
void	exec_one(t_pipe *pipex, t_input *input);
void	execute_pipes(t_pipe *pipex, t_input *input);
void	init_pipex(t_pipe *pipex);
int		good_files(t_input *cmd);
void	fd_update(t_input *input, t_pipe *pipex, int i);
void	fd_close_m(t_pipe *pipex, int i);
void	first_child(t_pipe *pipex, t_input *input);
void	rest_children(t_pipe *pipex, char *cmd_path, t_input *input);
int		check_valid(t_input *input, char *cmd_path);

#endif
