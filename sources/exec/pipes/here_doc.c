
#include "../../../includes/pipex.h"

/* static int	here_doc(char **argv)
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
	pipex()->fd_in = here_doc(argv);
	pipex()->flag = 42;
	pipex()->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex()->fd_out == -1)
		exit_pipex(NULL, 3);
} */

/* static void	expand_vars(char **line)
{
	char *new_line;


} */

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
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, limit) == 0) // ?? verify signals
		{
			if (!line) // ?? verify signals
				return (free(limit), ft_putendl_fd("", STDOUT_FILENO));
			if (line)
				return (free(line), free(limit));
			return ;
		}
		//expand_vars(&line); // !! Ask luis how to do this and the logic
		ft_putendl_fd(line,f_d);
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
	file_n = ft_calloc(len + 1, 1);
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
	file_n = random_file_gen();
	if (!file_n)
		return (-1);
	while (tmp) // ?? verify signals
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
	// ?? verify signals
	while (tmp)
	{
		if (tmp->l_read == 42000)
			tmp->l_read = here_doc(tmp->fd);
		// ?? verify signals
		tmp = tmp->next;
	}
	// ?? verify signals
	return(1);
}
