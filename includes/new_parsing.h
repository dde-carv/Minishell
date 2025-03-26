#ifndef NEW_PARSE_H
# define NEW_PARSE_H

#include "minishell.h"

void					new_parse(void);
void					args_to_cmd(void);
void					redirects_parsing(void);
char					*new_cut(char **s, int init, int end);
void					trim_spaces(char **s);
void					trim_front_spaces(char **s);
void					expantion_mark(void);
void					change_cmd(t_input **cmd);
void					create_args(t_input **cmd);
#endif
