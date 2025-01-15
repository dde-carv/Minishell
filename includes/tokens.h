#ifndef TOKENS_H
# define TOKENS_H

# define T_BUILTIN		42
# define T_LITERAL		43
# define T_PIPE			44
# define T_REDIRECT		45
# define T_HERE_DOC		46
# define T_FILE			47

# define SINGLE_QUOTE	'\''
# define DOUBLE_QUOTE	'\"'

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
	struct s_token	*previous;
}				t_token;


#endif
