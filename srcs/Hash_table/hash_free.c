#include "../../includes/minishell.h"

static void	free_this_node(t_node *node)
{
	if (node->next != NULL)
		free_this_node(node->next);
	free(node->key);
	free(node->value);
	free(node);
}

void	free_hash(t_hash *hash)
{
	size_t	index;
	t_node	*temp;

	index = 0;
	while (index < HASH_SIZE)
	{
		temp = hash->list[index];
		free_this_node(temp);
		index++;
	}
	free(hash);
}
