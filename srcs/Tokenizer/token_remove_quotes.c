#include "../../includes/minishell.h"



static void	copy_edited_str(char *str, char *new)
{
	size_t	index;

	new = (char *)ft_calloc(get_edit_size(str) + 1, sizeof(char));
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\'' || str[index] == '\"')
			move_quotes(str, new);
		if (str[index] == '$')
			expand_var();
		index++;
	}
}

char	**remove_quotes_and_expand(char **matrix)
{
	char	**new;
	char	**free_me;
	size_t	size;

	if (**matrix == '\0')
		return (matrix);
	free_me = matrix;
	new = (char **)ft_calloc(ft_matrixlen(matrix) + 1, sizeof(char *));
	size = 0;
	while (*matrix)
	{
		copy_edited_str(*matrix, new[size]);
		size++;
		matrix++;
	}
	ft_free_matrix(free_me);
	return (new);
}
