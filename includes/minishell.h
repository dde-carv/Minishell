/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:17:30 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 17:45:22 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _DEFAULT_SOURCE

# include <stddef.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/inc/libft.h"
# include "hashmap.h"
# include "parsing.h"
# include "colors.h"
# include "pipex.h"
# include "signals.h"

typedef struct s_pipe	t_pipe;

typedef struct s_minishell
{
	char	*promp;
	char	*line;
}				t_minishell;

typedef struct s_global
{
	int			error_status;
	int			signal;
	int			pipes;
	t_pipe		*pipex;
	t_input		*input;
	t_hashmap	*table;
	t_hashmap	*env;
	t_hashmap	*non_value_vars;
	t_minishell	*ms;
}				t_global;

typedef struct s_help
{
	int		pos;
	char	in_quotes;
	char	*new_str;
}	t_help;

/************************** clean **************************/

// Exits the program in a clean way
void		exit_minishell(void);
// Frees any char type array given
void		free_array(void **array);
// Frees any char type string given
void		free_pointer(void *str);

/*************************** env ***************************/

// Calls other functions to initialize enviroment variables
void		set_env(char **env);
// Duplicates env variables and put them in a hash table
t_hashmap	*hash_env(char **env);
// Updates the shell level when entering a new session
void		shlvl_update(void);
// Updates env variables during execution
void		update_under(void);
// Creates some env variables and put them in a hash table
t_hashmap	*create_hash_env(void);

/************************** data ***************************/

// Function that calls "global" struct
t_global	*minis(void);

/************************ executer *************************/

// Functions that calls if is builtin and execution
void		execute(void);
// Function to call the builtins
void		ft_exec_builtin(char *cmd, char **args, int fd, int exit_flag);
// Function to open all file descriptors
int			handle_fd(t_input **input);
// Function to verify if the command given is a builtin
int			is_builtin(char *cmd);

/************************* builtin *************************/

// Function that replicates cd (change directory)
void		ft_cd(char *path, int fd);
// Function that replicates pwd (print working directory)
void		ft_pwd(int fd);
// Function that replicates echo (prints to stdout the arguments given)
void		ft_echo(char **args, int fd);
// Function that replicates exit (responsible to exit clean)
void		ft_exit(char **args);
// Function that replicates unset (removes variables from env)
void		ft_unset(char **args);
// Function that replicates export (adds variables to env)
int			ft_export(char **args, int fd);
// Function to validate and add to export or env
int			add_var(char **args, int i);
// Function that creates a prompt, reads a line and add it to the history
void		set_input(void);
// Function that verifies if arguments are valid for env
void		ft_verify_env(char **args, int fd);
// Function that verifies if arguments are valid for cd
void		ft_verify_cd(char **path, int fd);
// Function that updates the env with the new PWD and OLDPWD
void		update_env_cd(char *pwd);
// Puts env and session vars hashmaps into an array
char		**hashmap_quotes_array_and_non_value_vars(void);
// Puts env variables into an array
char		**hashmap_to_array(void);
// Sorts an array in ascii oreder
void		quick_sort(char **array, int left, int right);
// Gives the length of the array
int			array_len(char **array);
// Takes a string and aplies that string to every position in the array
void		ft_strjoin_to_array(char *str, char **array);
// Prints any char type array given and prints it to any file discriptor
void		print_array_fd(char **array, int fd);
// Splites the string given by the first occurence of 'c'
char		**split_into2(char *arg, char c);

/************************** error **************************/

# define NOT_FOUND "command not found"
# define NO_OLDPWD "OLDPWD not set"
# define NO_HOME "HOME not set"
# define NO_FILE_OR_DIR "No such file or directory"
# define SYNTAX_ERROR "syntax error"
# define TOO_MANY_ARGS "too many arguments"
# define NUM_ARG_REQUIRED "numeric argument required"
# define INVALID_IDENTIFY "not a valid identifier"

// Display error message in stderror
void		error_mess(char *input, char *message, int status);

#endif
