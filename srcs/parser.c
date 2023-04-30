#include "../includes/minishell.h"

void	get_words(char *str)
{
	char **tree;
	int i;

	i = 0;
	tree = ft_split(str, ' ');
	while (tree[i] && tree)
	{
		printf("%s\n", tree[i]);
		i++;
	}
	free(tree);
	free(str);
}

void	parser(char *str, t_hash *hash)
{
	(void)hash;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	get_words(separator(str));
}