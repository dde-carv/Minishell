#include "../../inc/minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ENTRY_SIZE 100
#define HASH_TABLE_SIZE 10

typedef struct s_entry2
{
	char	*key;
	char	*value;
}	t_entry2;

t_entry2 *hash_table[HASH_TABLE_SIZE];

void    create_table()
{
    int i = 0;
    while (i < HASH_TABLE_SIZE)
    {
        hash_table[i] = NULL;
        i++;
    }
    // table is empty
}

void    print_table()
{
    ft_printf("start\n");
    int i = 0;
    while (i < HASH_TABLE_SIZE)
    {
        if (hash_table[i] == NULL)
            ft_printf("\t%i\t---\n", i);
        else
        {
            ft_printf("\t%i\t%s\n", i, hash_table[i]->key);
        }
        i++;
    }
    ft_printf("end\n\n");
}

unsigned int hash(char *entry)
{
    int i = 0;
    int len = strnlen(entry, MAX_ENTRY_SIZE);
    unsigned int hash_value = 0;
    
    while (i < len)
    {
        hash_value = hash_value + entry[i];
        hash_value = (hash_value * entry[i]) % HASH_TABLE_SIZE;
        i++;
    }
    return (hash_value);
}

bool    hash_table_insert(t_entry2 *entry)
{
    if (entry == NULL)
        return NULL;
    int index = hash(entry->key);
    if (hash_table[index] != NULL)
        return false;
    hash_table[index] = entry;
    return true;
}

//find an entry in the table by their key
t_entry2    *hash_table_lookup (char *key)
{
    int index = hash(key);
    if (hash_table[index] != NULL &&
        ft_strncmp(hash_table[index]->key, key, HASH_TABLE_SIZE) == 0)
        return (hash_table[index]);
    else
        return NULL;
}

//delete an entry in the table by their key
t_entry2    *hash_table_delete (char *key)
{
    int index = hash(key);
    if (hash_table[index] != NULL &&
        ft_strncmp(hash_table[index]->key, key, HASH_TABLE_SIZE) == 0)
        {
            t_entry2 *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
        }
    else
        return NULL;
}

int main()
{
    create_table();
   // print_table();

    t_entry2 cd = {.key="cd", .value= ".."};
    t_entry2 echo = {.key="echo"};
    t_entry2 pwd = {.key="pwd"};
    t_entry2 ls = {.key="ls"};

    hash_table_insert(&cd);
    hash_table_insert(&echo);
    hash_table_insert(&pwd);
    hash_table_insert(&ls);
    print_table();

    // lookup for a key entry that we know is in the table
    t_entry2 *tmp = hash_table_lookup("echo");
    ft_printf("Looking for echo\n");
    if (tmp == NULL)
        ft_printf("Not found!\n");
    else
        ft_printf("Found! %s.\n", tmp->key);
    
    // lookup for a key entry that we know is NOT in the table
    tmp = hash_table_lookup("Luis");
    ft_printf("Looking for Luis\n");
    if (tmp == NULL)
        ft_printf("Not found!\n\n");
    else
        ft_printf("Found! %s.\n", tmp->key);

    // delete a key entry that we know is in the table
    ft_printf("Now we'll delete cd from table\n");
    hash_table_delete("cd");
    
    print_table();

    /* ft_printf("echo => %u\n", hash("echo"));
    ft_printf("cd => %u\n", hash("cd"));
    ft_printf("pwd => %u\n", hash("pwd"));
    ft_printf("touch => %u\n", hash("touch"));
    ft_printf("env => %u\n", hash("env")); */
    return (0);
}