
#ifndef MINISHELL_H
# define MINISHELL_H

# include "hashmap.h"
# include "pipex.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define YES_MALL 1
# define NY_MALL 0
# define NO_MALL 42
# define MALL_ERROR 2

typedef struct s_env
{
	char	*var_n;
	char	*var_v;
	struct s_env	*next;
}				t_env;

typedef struct s_minishell
{
	char	*promp;
	char	*full_promp;
	char	*line;
	char	*old_pwd;
}				t_minishell;

typedef struct s_global
{
	t_env	*my_env;
	t_hashmap	*hash;
	t_minishell	*ms;
}				t_global;

////////////////////////// clean //////////////////////////

//Cleans the environment variables from our array
void	ft_clean_envvars(char **vars, int size);


////////////////////////// env //////////////////////////

//Duplicates the environment variables so we can modify them
void	env_dup(char **env);
//Creates the environment variables if they don't exist
void	env_create(void);
//Creates the variables to be put in the env
void	create_var(char *var_n, char *var_v, int flag_mall);
//Returns the value of the var that is given
char	*get_var(char *varn);
//Frees variables if malloc alocation fails
void	env_fail(int flag, char *var_n, char *var_v, int flag_mall);


////////////////////////// data //////////////////////////

// Function that calls "global" struct
t_global	*minis(void);

void	free_env(void);
void	exit_minishell(int flag);
void	error_mag(int flag);

#endif
