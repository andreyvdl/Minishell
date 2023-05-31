#include "../../includes/minishell.h"

static size_t	count_variables(t_hash *hash)
{
	size_t	size;
	size_t	walker;
	t_node	*node;

	size = 0;
	walker = 0;
	while (walker < HASH_SIZE)
	{
		node = hash->list[walker];
		while (node != NULL)
		{
			if (node->value != NULL)
				size++;
			node = node->next;
		}
		walker++;
	}
	return (size);
}

static void	fill_matrix(char **matrix, t_hash *hash)
{
	size_t	walker;
	t_node	*node;
	char	*temp;

	walker = 0;
	while (walker < HASH_SIZE)
	{
		node = hash->list[walker];
		while (node != NULL)
		{
			if (node->value != NULL)
			{
				temp = ft_strjoin(node->key, "=");
				*matrix = ft_strjoin(temp, node->value);
				free(temp);
				matrix++;
			}
			node = node->next;
		}
		walker++;
	}
}

char	**hash_to_matrix(t_hash *hash)
{
	char	**matrix;

	matrix = (char **)ft_calloc(count_variables(hash) + 1, sizeof(char *));
	fill_matrix(matrix, hash);
	return (matrix);
}
