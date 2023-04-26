#include "../includes/minishell.h"

unsigned int hash_code(char *key)
{
	unsigned long	hash = 5381;
	unsigned int	c;
	while (*key){
		c = *key;
		hash = ((hash << 5) + hash) + c;
		key++;
	}
	return (hash % HASH_SIZE);
}

t_node *create_node(char *key, char *value){
	t_node *node = (t_node *)malloc(sizeof(t_node));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

