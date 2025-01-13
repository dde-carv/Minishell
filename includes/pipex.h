/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:18:46 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/16 22:21:05 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_cmd
{
	int				fd[2];
	char			*cmd;
	char			*path;
	char			**av;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}		t_cmd;

typedef struct s_pipe
{
	int			pid;
	int			flag;
	int			fd_in;
	int			fd_out;
	char		**paths;
	t_cmd		*first;
}		t_pipe;

t_pipe	*data(void);
void	free_all_cmds(char **cmds);
void	exit_pipex(t_cmd *input, int error);
void	father_son(t_cmd *input, char **envp);
void	ft_addcmd(t_cmd **input, t_cmd *new);
t_cmd	*ft_newcmd(char *cmd, char *path, int is_last);
char	*check_path(char *cmd, char **paths);
char	**get_path(char **envp);
void	here_doc_main(int argc, char **argv);

#endif
