#include "../../includes/minishell.h"

t_fd	*ft_fd_new(char *name, int fd, t_type type)
{
	t_fd	*n;

	n = ft_calloc(sizeof(t_fd), 1);
	if (!n)
		return (NULL);
	n->name = name;
	n->fd = fd;
	n->type = type;
	n->next = NULL;
	return (n);
}
