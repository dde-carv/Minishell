#include "minishell.h"

int	handle_fd(t_input **input)
{
	t_fd	*fd;

	fd = (*input)->fd;
	while (fd)
	{
		take_quotes(&fd->file_n);
		if (fd->type == )
	}
}
