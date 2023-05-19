#include "../../includes/minishell.h"

void	heredoc(t_hash *hash, t_redirect *this)
{
	char	*input;
	char	**overview;
	int		j;

	while (1)
	{
		input = readline("> ");
		overview = ft_split(expand_vars(input, hash), -7);
		j = 0;
		while (overview && *overview&&overview[j])
		{
			if (ft_strcmp(overview[j], this->delimiter) == 0)
				return;
			j++;
		}
		free(input);
	}
	ft_free_matrix((void **)overview);
}