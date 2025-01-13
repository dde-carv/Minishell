#ifndef HASHMAP_H
# define HASHMAP_H

#include "minishell.h"

typedef struct s_entry
{
    char *key;
    char *value;
    struct s_entry *next;
}               t_entry;

typedef struct s_hashmap
{
    t_entry **pairs;
    unsigned int    count;
    unsigned int    size;
}               t_hashmap;

#endif
