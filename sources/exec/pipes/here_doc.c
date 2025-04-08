/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:19:48 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 16:36:36 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	rl_hook(void)
{
	if (g_sig)
	{
		rl_done = 1;
	}
	return (0);
}

static void	exec_hd(t_fd **fd, char *file_n, int f_d)
{
	char	*line;
	char	*limit;

	if (f_d == -1)
		return ;
	limit = ft_strdup((*fd)->file_n);
	free_pointer((*fd)->file_n);
	(*fd)->file_n = ft_strdup(file_n);
	(*fd)->fd = f_d;
	rl_event_hook = rl_hook;
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, limit) == 0 || g_sig)
		{
			if (!line && !g_sig)
				return (free(limit), ft_putendl_fd("", STDOUT_FILENO));
			if (line)
				return (free(line), free(limit));
			return ;
		}
		ft_putendl_fd(line, f_d);
		free(line);
	}
	return (free(limit));
}

static char	*random_file_gen(void)
{
	int			i;
	int			len;
	char		*file_n;
	static char	*chararray;

	chararray = CHARS;
	srand(time(NULL));
	len = 15;
	file_n = ft_calloc(len + 5, 1);
	if (!file_n)
		return (NULL);
	ft_strcpy(file_n, "/tmp/.");
	i = 5;
	while (++i < len)
		file_n[i] = chararray[rand() % (ft_strlen(chararray) - 1)];
	file_n[i] = '\0';
	return (file_n);
}

static int	here_doc(t_fd *fd)
{
	int		f_d;
	char	*file_n;
	t_fd	*tmp;

	f_d = 0;
	tmp = fd;
	if (!*tmp->file_n)
		return (error_mess("here_doc", SYNTAX_ERROR, 2), -1);
	file_n = random_file_gen();
	if (!file_n)
		return (-1);
	while (tmp && g_sig == 0)
	{
		if (tmp->type == HEREDOC)
		{
			f_d = open(file_n, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			exec_hd(&tmp, file_n, f_d);
		}
		tmp = tmp->next;
		if (f_d > 0)
			ft_close(f_d);
	}
	free_pointer(file_n);
	return (f_d);
}

int	check_for_hd(t_input *input)
{
	t_input	*tmp;

	tmp = input;
	minis()->signal = 2;
	load_signals();
	while (tmp)
	{
		if (tmp->l_read == 1000)
			tmp->l_read = here_doc(tmp->fd);
		if (g_sig)
			break ;
		tmp = tmp->next;
	}
	minis()->signal = 1;
	load_signals();
	return (g_sig == 0);
}
