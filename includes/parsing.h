#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef enum s_type
{
	APPEND,
	TRUNCATE,
	HEREDOC,
	REVERSE,
}					t_type;

typedef struct s_fd
{
	int			fd;
	char		*file_n;
	t_type		type;
	struct s_fd	*next;
}					t_fd;

typedef struct s_input
{
	char			*cmd;
	char			*arg;
	char			**args;
	char			*path; //!! This is going to be moved to pipex.h
	t_fd			*fd;
	int				l_write;
	int				l_read;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

/************************* Parsing *************************/

// Function that processes and sets the arguments for an input command.
void	args(t_input **input);
// Parses the raw input string and builds the input linked list.
void	parse_input(void);
// Scans the input for redirection operators and constructs the corresponding file descriptors.
void	parse_redirects(t_input **cmd);
// Updates the quote state.
void	update_quote_state(char c, char *in_quotes);
// 
void	update_cmd_args(t_input **cmd, char *processed_str);

// Cleans leading/trailing spaces and other unwanted characters from the input.
void	clean_content(void);
// Applies necessary transformations to the input string before execution.
void	transform_input(void);
// Processes any environment variable expansions present in the string.
void	expantions(char **s);
// Replaces the expansion marker in the string with its actual value.
char	*sub_expantion(char *str, char *value);
// Retrieves the value corresponding to an environment variable reference.
char	*get_value(char *s);
// Splits the input string into tokens based on specific delimiters.
char	**split_value(char *str);



// Verifies that all quotes in the string are properly closed.
bool	closed_quotes(char *str);
// Checks if the string contains an environment variable expansion.
bool	is_expantion(char *str);
// Validates the overall syntax of the input.
bool	is_valid(void);
/* // Determines if the string requires additional splitting for proper parsing.
bool	needs_split(char *s); */
// Determines if the string has any redirections.
bool	has_redirection(char *s);

/* char	*new_cut(char **s, int init, int end);
void	change_input(t_input **cmd);
void	create_args(t_input **input);
void	expantion_mark(void);
void	args_to_cmd(void);
void	new_parse(void);
void	redirects_parsing(void);
void	trim_spaces(char **s);
void	trim_front_spaces(char **s); */

/************************* Parsing list functions *************************/

// Returns the total number of nodes in the input linked list.
int		ft_input_lstsize(t_input **lst);
// Creates a new input node with the specified command and argument.
t_input	*ft_input_lstnew(char *cmd, char *arg);
// Adds a new input node to the end of the t_input linked list.
void	ft_input_lstadd_back(t_input **lst, t_input *n);
// Frees a single input node.
void	ft_input_lstdelone(t_input **lst);
// Frees the entire list.
void	ft_input_lstclear(t_input **lst);

/************************* Parsing file descriptor functions *************************/

// Adds a new file descriptor node to the end of the t_fd linked list.
void	ft_fd_add_back(t_fd **lst, t_fd *n);
// Creates and returns a new file descriptor node with the specified file name, file descriptor and type.
t_fd	*ft_fd_new(char *file_n, int fd, t_type type);
// Function to delete fd nodes
void	ft_fd_del(t_fd	**fd);

void	change_cmd(t_input **cmd);

#endif
