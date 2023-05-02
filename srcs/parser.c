#include "../includes/minishell.h"

void	get_words(char *str, t_hash *hash)
{
	char **tree;
	int i;

	i = 0;
	(void)hash;
	tree = ft_split(str, ' ');
	while (tree[i] && tree)
	{
		ft_printf("[%s]\n", tree[i]);
		i++;
	}
	free(tree);
}

void	parser(char *str, t_hash *hash)
{
	char	*clean_cmd;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	clean_cmd = expand_vars(separator(str), hash);
	get_words(clean_cmd, hash);
}
