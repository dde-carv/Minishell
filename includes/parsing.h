#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef struct s_input	t_input;

void	parse_input(void);

// Parsing list
t_input	*ft_input_lstnew(char *cmd, char *arg);
void	ft_input_lstadd_back(t_input **lst, t_input *n);
void	ft_input_lstdelone(t_input **lst);

#endif