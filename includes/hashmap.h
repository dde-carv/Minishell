#ifndef HASHMAP_H
# define HASHMAP_H

typedef struct s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}				t_entry;

typedef struct s_hashmap
{
	// Contains an array of pointers to entries
	unsigned int	count;
	unsigned int	size;
	t_entry			**entries;
}				t_hashmap;

unsigned long	hash_function(const char *key, unsigned int size);
t_hashmap		*create_table(unsigned int size);
t_entry			*create_entry(char *key, char *value);
void			insert_in_table(char *key, char *value, t_hashmap *table);
char			*hashmap_search(t_hashmap *table, char *key);
void			handle_collision(t_hashmap *table, unsigned long index, t_entry *new_entry);
void			hashmap_delete(t_hashmap *table, char *key);
void			free_entry(t_entry *entry);
void			free_table(t_hashmap *table);
void			hashmap_print_table(t_hashmap *table);

#endif
