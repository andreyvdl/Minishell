#include "../../include/minishell.h"

static void	remove_it(t_node *prev, t_node *curr)
{
	prev->next = curr->next;
	ft_free(curr->value);
	free(curr->key);
	free(curr);
}

static void	remove_it_2(t_node *prev, t_node *curr, t_hash *hash, \
unsigned const int index)
{
	hash->list[index] = curr->next;
	ft_free(curr->value);
	free(curr->key);
	free(curr);
}

void	remove_node(t_hash *hash, char *key)
{
	unsigned const int	index = hash_code(key);
	t_node				*prev;
	t_node				*curr;

	prev = NULL;
	curr = hash->list[index];
	while (node != NULL)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			if (prev != NULL)
				remove_it(prev, curr);
			else
				remove_it_2(prev, curr, hash, index);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}
