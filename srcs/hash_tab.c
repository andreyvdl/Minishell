#include "../includes/minishell.h"

static unsigned int hash_code(char *key)
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

void	insert_node(t_hash *hash, char *key, char *value)
{
	unsigned const int index = hash_code(key);
	t_node *node = hash->list[index];
	if (node == NULL)
		hash->list[index] = create_node(key, value);
		else
		{
			while (node)
			{
				if (node->next)
				{
					node->next = create_node(key, value);
					break;
				}
				node = node->next;
			}
		}
}