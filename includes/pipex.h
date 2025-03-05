/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:18:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/03/03 13:14:36 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "minishell.h"

typedef struct s_pipe
{
	int		argc;
	int		(*fd)[2];
	int		heredoc_pid;
	int		*pids;
	char	**envp;
	char	**env_paths;
	char	**cmd_paths;

}		t_pipe;


void	ft_exec_pipex(void);

#endif
