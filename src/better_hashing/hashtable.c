#include "hashtable.h"

typedef struct entry
{
	char *key;
	void *object;
	struct entry *next;
}   entry;

typedef struct _hash_table
{
	size_t size;
	hashfunction *hash;
	entry **elements;
}   hash_table;

static size_t hash_table_index(hash_table *ht, const char *key)
{
	size_t result = (ht->hash(key, strlen(key)) % ht->size);
	return (result);
}

hash_table *hash_table_create(hashfunction *hf, size_t size)
{
	hash_table *ht = malloc(sizeof(*ht));
	ht->size = size;
	ht->hash = hf;
	// note that calloc zeros out the memory
	ht->elements = calloc(sizeof(entry*), ht->size);
	return (ht);
}

void hash_table_destroy(hash_table *ht)
{
	size_t i;

	i = 0;
	if (ht == NULL)
		return ;
	
	while(i < ht->size)
	{
		entry *current = ht->elements[i];
		while (current != NULL)
		{
			entry *next = current->next;
			free(current->key);
			free(current->object);
			free(current);
			current = next;
		}
	}
	free(ht->elements);
	free(ht);
}

void hash_table_print(hash_table *ht)
{
	printf("\n_______ Start Table _______\n\n");
	size_t i = 0;
	while (i < ht->size)
	{
		if (ht->elements[i] == NULL)
		{
			printf("\t%zu\t---\n", i);
		}
		else
		{
			printf("\t%zu\t", i);
			entry *tmp = ht->elements[i];
			while (tmp != NULL)
			{
				printf("\"%s\"(%p) - ", tmp->key, tmp->object);
				tmp = tmp->next;
			}
			printf("\n");
		}
		i++;
	}
	printf("\n_______ End Table _______\n\n");
}

bool hash_table_insert(hash_table *ht, const char *key, void *obj)
{
	if (key == NULL || obj == NULL || ht == NULL)
		return (false);
	size_t index = hash_table_index(ht, key);

	if (hash_table_lookup(ht, key) != NULL)
	return (false);

	//create a new entry
	entry *e = malloc(sizeof(*e));
	e->object = obj;
	e->key = malloc(strlen(key) + 1);
	strcpy(e->key, key);

	//insert entry
	e->next = ht->elements[index];
	ht->elements[index] = e;
	return (true);
}

void *hash_table_lookup(hash_table *ht, const char *key)
{
	if (key == NULL || ht == NULL)
        return (NULL);
	size_t index = hash_table_index(ht, key);

	entry *tmp = ht->elements[index];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	return (tmp->object);
}

void *hash_table_delete(hash_table *ht, const char *key)
{
	if (key == NULL || ht == NULL)
        return (false);
	size_t index = hash_table_index(ht, key);

	entry *tmp = ht->elements[index];
	entry *prev = NULL;
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	if (prev == NULL)
	{
		//deleting the head of the list
		ht->elements[index] = tmp->next;
	}
	else
	{
		//deleting from somewhere not the head
		prev->next = tmp->next;
	}
	void *result = tmp->object;
	free(tmp);
	return (result);
}
