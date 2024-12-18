
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

////////////////////////// clean //////////////////////////

//Cleans the environment variables from our array
void	ft_clean_envvars(char **vars, int size);


////////////////////////// env //////////////////////////

//Duplicates the environment variables so we can modify them
void	env_dup(t_minishell *ms, char **env);
//Creates the environment variables if they don't exist
void	env_create(t_minishell *ms);

#endif
