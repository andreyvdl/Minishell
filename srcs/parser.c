#include "../includes/minishell.h"

void	get_words(char *str, t_hash *hash)
{
	char **tree;
	int i;

	i = 0;
	tree = ft_split(str, ' ');
	while (tree[i] && tree)
	{
		expand_vars(tree[i], hash);
		i++;
	}
	free(tree);
}

void	parser(char *str, t_hash *hash)
{
	(void)hash;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_words(separator(str), hash);
}