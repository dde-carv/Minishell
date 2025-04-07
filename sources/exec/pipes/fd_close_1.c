#include "../../../includes/pipex.h"

void	fd_close_all(t_input *input)
{
	t_input	*tmp;

	tmp = input;
	while (tmp)
	{
		close_fd(tmp);
		tmp = tmp->next;
	}
}
