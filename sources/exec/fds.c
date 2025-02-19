#include "minishell.h"

int	handle_fd(t_input **input)
{
	t_fd	*fd;

	fd = (*input)->fd;
	while (fd)
	{
		take_quotes(&fd->file_n);
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
	return (1);
}
