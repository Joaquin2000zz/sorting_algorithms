#include "deck.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * hash_table_create - function which creates a hash table
 * @size: hash table size
 * Return: a pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newHashTable = NULL;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	newHashTable = malloc(sizeof(hash_table_t));
		if (!newHashTable)
			return (NULL);
	newHashTable->size = size;
	newHashTable->array = malloc(sizeof(hash_node_t *) * size);
	if (!newHashTable->array)
	{
		free(newHashTable);
		return (NULL);
	}
	for (i = 0;  newHashTable->array[i]; i++)
		newHashTable->array[i] = NULL;
	return (newHashTable);
}

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * key_index - function that gives you the index of a key
 * @key: the key of the array hash
 * @size: size of the array of the table
 * Return: the inex at the key value
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

/**
 * hash_table_set - function that adds an element to index's stack
 * @ht: the hash table
 * @key: the key of the linked list into the hash table
 * @value: value to insert in the list of the especific index
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_node = NULL;

	if (!ht || !key || !value)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
		if (!new_node)
			return (0);
	index = key_index((const unsigned char *)key, ht->size);
	new_node->key = strdup(key);
	new_node->value = value;
	if (!ht->array[index])
		new_node->next = NULL;
	else
		new_node->next = ht->array[index];
	ht->array[index] = new_node;
	/*printf("nodocreadocn value: %s y key: %s index: %lu\n",*/
	/*new_node->value, new_node->key, index);*/
	return (1);
}

void sort_deck(deck_node_t **deck)
{
	deck_node_t *i;
	hash_table_t *hashTable;
	unsigned long int size = 0;

	i = *deck;

	while (i)
	{
		i = i->next;
		size++;
	}

	hashTable = hash_table_create(size);

	i = *deck;

	while (i)
	{
		hash_table_set(hashTable, i->card->value, i->card->value->kind);
		i = i->next;
	}
}
