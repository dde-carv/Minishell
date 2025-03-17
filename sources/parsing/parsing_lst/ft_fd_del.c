#include "minishell.h"

static void	ft_fd_delone(t_fd **lst)
{
	t_fd	*temp;

	temp = *lst;
	free_pointer(temp->file_n);
	if (temp->fd > 0)
		close(temp->fd);
	free(temp);
}

void	ft_fd_del(t_fd	**fd)
{
	t_fd	*list_t;
	t_fd	*list_temp;

	list_t = *fd;
	if (!*fd)
		return ;
	while (list_t)
	{
		list_temp = list_t->next;
		ft_fd_delone(&list_t);
		list_t = list_temp;
	}
	*fd = NULL;
}
