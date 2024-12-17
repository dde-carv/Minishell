
#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "ft_search.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	char	*promp;
	char	*full_promp;
	char	*line;
	char	**my_env;
	t_hash	*ht;
	t_node	*cmds;
}				t_minishell;

#endif
