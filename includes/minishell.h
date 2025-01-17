
#ifndef MINISHELL_H
# define MINISHELL_H

# include "hashmap.h"
# include "input.h"
# include "tokens.h"
# include "pipex.h"
# include "../libft/inc/libft.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	char	*promp;
	char	*line;
}				t_minishell;

typedef struct s_global
{
	int			error_status;
	t_hashmap	*env;
	t_hashmap	*sesion_vars;
	t_minishell	*ms;
}				t_global;

/************************** clean **************************/

// Exits the program in a clean way
void	exit_minishell(int flag);

/*************************** env ***************************/

// Calls other functions to initialize enviroment variables
void	set_env(char **env);
// Duplicates env variables and put them in a hash table
t_hashmap	*hash_env(char **env);
// Creates some env variables and put them in a hash table
t_hashmap	*create_hash_env(void);

/************************** data ***************************/

// Function that calls "global" struct
t_global	*minis(void);

/************************* builtin *************************/

// Function that replcates cd (change directory)
void	ft_cd(char *path);
//Function that replcates pwd (print working directory)
void	ft_pwd(void);
// Function that creates a prompt, reads a line and add it to the history
void	set_input(void);

/************************** error **************************/

# define NOT_FOUND "command not found."
# define NO_OLDPWD "OLDPWD not set."
# define NO_HOME "HOME not set."
# define NO_FILE_OR_DIR "No such file or directory."
# define SYNTAX_ERROR "syntax error."
# define NUM_ARG_REQUIRED "numeric argument required."

// Display error message in stderror
void	error_mess(char *input, char *message, int status);

#endif
