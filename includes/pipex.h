/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:18:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/24 15:59:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "minishell.h"

typedef struct s_pipe
{
	int			pid;
	int			flag;
	char		**paths;
	t_input		*first;
}		t_pipe;

void	free_all_cmds(char **cmds);
void	exit_pipex(t_input *input, int error);
void	father_son(t_input *input, char **envp);
void	ft_addcmd(t_input **input, t_input *new);
t_input	*ft_newcmd(char *cmd, char *path, int is_last);
char	*check_path(char *cmd, char **paths);
char	**get_path(char **envp);
void	here_doc_main(int argc, char **argv);

#endif
