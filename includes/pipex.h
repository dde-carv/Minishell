
#ifndef PIPEX_H
# define PIPEX_H

# include "minishell.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

# define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

/* typedef struct s_cmd
{
	int				fd[2];
	char			*cmd;
	char			*path;
	char			**av;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}		t_cmd; */

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
//	int			fd_in;
//	int			fd_out;
	char		**env;
	char		**cmd_paths;
	char		**env_paths;
}		t_pipe;

/* t_pipe	*data(void);
void	free_all_cmds(char **cmds);
void	father_son(t_cmd *input, char **envp);
void	ft_addcmd(t_cmd **input, t_cmd *new);
t_cmd	*ft_newcmd(char *cmd, char *path, int is_last);
char	*check_path(char *cmd, char **paths);
char	**get_path(char **envp);
void	here_doc_main(int argc, char **argv);
int		ft_father_son(t_input *input, char **envp); */

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

int	good_files(t_input *cmd);

void	fd_update(t_input *input, t_pipe *pipex, int i);

void	fd_close_m(t_pipe *pipex, int i);

void	first_child(t_pipe *pipex, t_input *input);

void	rest_children(t_pipe *pipex, char *cmd_path, t_input *input);

int		check_valid(t_input *input, char *cmd_path);

#endif
