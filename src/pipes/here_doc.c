/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:52:21 by dde-carv          #+#    #+#             */
/*   Updated: 2024/11/19 12:59:03 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static int	here_doc(char **argv)
{
	int		fd_in;
	char	*line;

	fd_in = open(".temp", O_WRONLY | O_CREAT, 0644);
	if (fd_in == -1)
		exit_pipex(NULL, 1);
	ft_printf("> ");
	line = get_next_line(0);
	while (1)
	{
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0 && \
			(ft_strlen(line) - 1) == ft_strlen(argv[2]))
			break ;
		write(fd_in, line, ft_strlen(line));
		free(line);
		ft_printf("> ");
		line = get_next_line(0);
	}
	free(line);
	close(fd_in);
	fd_in = open(".temp", O_RDONLY | O_CREAT, 0644);
	return (fd_in);
}

void	here_doc_main(int argc, char **argv)
{
	data()->fd_in = here_doc(argv);
	data()->flag = 42;
	data()->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	exit_pipex(NULL, 3);
}
