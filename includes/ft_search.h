
#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "minishell.h"

typedef struct s_entry	t_entry;
typedef struct s_node	t_node;
typedef struct s_hash	t_hash;

struct s_entry
{
	char	*key;
	char	*value;
};

struct s_node
{
	t_entry		entry;
	struct s_node	*next;
};

/* struct s_hash
{
	t_node		**array;
	size_t		size;
}; */





#endif
