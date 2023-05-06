#include "../../includes/minishell.h"

void	env(t_hash *hash)
{
	t_node	*node;

	for (int i = 0; i < HASH_SIZE; i++)
	{
		node = hash->list[i];
		while (node)
		{
			ft_printf("%s=%s\n", node->key, search(hash, node->key));
			node = node->next;
		}
	}
}