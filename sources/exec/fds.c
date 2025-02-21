#include "minishell.h"

static int	get_last_w(t_fd *fd)
{
	t_fd	*f_d;
	int		file_d;

	f_d = fd;
	file_d = 1;
	while (f_d)
	{
		if (f_d->type == TRUNCATE || f_d->type == APPEND)
			file_d = f_d->fd;
		f_d = f_d->next;
	}
	return (file_d);
}

static int	get_last_r(t_fd *fd)
{
	t_fd	*f_d;
	int		file_d;

	f_d = fd;
	file_d = 1;
	while (f_d)
	{
		if (f_d->type == TRUNCATE)
			file_d = f_d->fd;
		else if (f_d->type == APPEND)
			file_d = 42000;
		f_d = f_d->next;
	}
	return (file_d);
}

int	handle_fd(t_input **input)
{
	t_fd	*fd;

	fd = (*input)->fd;
	while (fd)
	{
		//take_quotes(&fd->file_n); // !! Can create problems if expansions don't take all the quotes
		if (fd->type == TRUNCATE)
			fd->fd = open(fd->file_n, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd->type == APPEND)
			fd->fd = open(fd->file_n, O_CREAT | O_APPEND | O_WRONLY, 0664);
		if (fd->type == REVERSE)
			fd->fd = open(fd->file_n, O_RDONLY, 0644);
		if (fd->type == HEREDOC)
			fd->fd = 42000;
		if (fd->fd == -1)
			break ;
		fd = fd->next;
	}
	if (fd && fd->fd == -1)
	{
		error_mess(fd->file_n, NO_FILE_OR_DIR, 1);
		return (0);
	}
	(*input)->l_write = get_last_w((*input)->fd);
	(*input)->l_read = get_last_r((*input)->fd);
	return (1);
}
