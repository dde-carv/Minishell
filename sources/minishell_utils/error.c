/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:20:36 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_pipes(void)
{
	if (minis()->pipes == -1)
		fd_close(minis()->pipex);
	else if (minis()->pipes == 0)
		close_one_fd(minis()->pipex);
	else
		fd_close_m(minis()->pipex, minis()->pipes);
	fd_close_all(minis()->input);
	exit_pipex(minis()->pipex);
	free_pointer(minis()->ms->line);
	ft_input_lstclear(&minis()->input);
	free_table(minis()->env);
	free_table(minis()->non_value_vars);
	free_table(minis()->table);
	clear_history();
	exit(minis()->error_status);
}

void	exit_minishell(void)
{
	if (minis()->pipex)
		clear_pipes();
	free_pointer(minis()->ms->line);
	if (minis()->input)
		ft_input_lstclear(&minis()->input);
	if (minis()->env)
	{
		free_table(minis()->env);
		free_table(minis()->non_value_vars);
		free_table(minis()->table);
	}
	clear_history();
	exit(minis()->error_status);
}

void	error_mess(char *input, char *message, int status)
{
	char	*error_out;

	error_out = ft_strjoin_var(
			7,
			BOLD_RED,
			"minishell: ",
			RED, input,
			": ", message,
			RESET_COLOR);
	ft_putendl_fd(error_out, 2);
	minis()->error_status = status;
	free(error_out);
}
