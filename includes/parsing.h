#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef enum s_type
{
	APPEND,
	CREATE,
	HEREDOC,
	REVERSE,
}					t_type;

typedef struct s_fd
{
	int			fd;
	char		*name;
	t_type		type;
	struct s_fd	*next;
}					t_fd;

typedef struct s_input
{
	char			*cmd;
	char			*arg;
	char			**args;
	t_fd			*fd;
	struct s_input	*next;
}				t_input;

void	parse_input(void);

// Parsing list
t_input	*ft_input_lstnew(char *cmd, char *arg);
void	ft_input_lstadd_back(t_input **lst, t_input *n);
void	ft_input_lstdelone(t_input **lst);

void	free_t_input(t_input *input);
void	args(t_input **lst);
void	free_args(char **args);
void	parse_redirects(t_input **cmd);

#endif
