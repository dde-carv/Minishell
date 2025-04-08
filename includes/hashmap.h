/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:17:21 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:17:23 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

typedef enum s_action
{
	ENTER,
	FIND,
}				t_action;

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

// Main function for hashing where we find the index
unsigned long	hash_function(const char *key, size_t size);
// Create the hashtable and allocates memory for it
t_hashmap		*create_table(unsigned int size);
// Creates a pointer to a new Hashmap entry
t_entry			*create_entry(char *key, char *value);
// Inserts the key and value into the table
void			insert_in_table(char *key, char *value, t_hashmap *table);
// Searches the key in the table and returns its value
char			*hashmap_search(t_hashmap *table, char *key);
// If collision is detected it creates a node in an index of the table
void			handle_collision(t_hashmap *table, \
	unsigned long index, t_entry *new_entry);
// Searches the key in the table and deletes that key and value
void			hashmap_delete(t_hashmap *table, char *key);
// Frees individual keys, values and the nodes (the whole table)
void			free_t_entry(t_entry *entry);
// Frees every memory related to the table
void			free_table(t_hashmap *table);
// Prints the table
void			hashmap_print_table(t_hashmap *table);
// Function that acts depending on the action provided
t_entry			*hash_action(t_hashmap *table, t_entry entry, t_action action);

#endif
