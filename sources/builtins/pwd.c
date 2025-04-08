/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:05 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:06 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(int fd)
{
	char	*cwd;

	minis()->error_status = 0;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (error_mess("pwd", NO_FILE_OR_DIR, 1), (void)cwd);
	ft_putendl_fd(cwd, fd);
	free(cwd);
}
