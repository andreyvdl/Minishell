#include "../../includes/minishell.h"

// void	heredoc()
// {
// 	char	*input;
// 	char	**overview;
// 	int		j;

// 	while (1)
// 	{
// 		input = readline("> ");
// 		overview = ft_split(expand_vars(input, hash), -7);
// 		j = 0;
// 		while (overview && *overview&&overview[j])
// 		{
// 			if (ft_strcmp(overview[j], this->delimiter) == 0)
// 				return;
// 			j++;
// 		}
// 		free(input);
// 	}
// 	ft_free_matrix((void **)overview);
// }

static char	*remove_quotes(char *limiter)
{
	while (*limiter)
	{
		if (*limiter == '\'')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
			while (*limiter != '\'' && *limiter)
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
		}
		else if ()
	}
}

static int	without_expansions(char *limiter, t_command *son)
{
	char	*temp;

	temp = remove_quotes(limiter);

}

int	heredoc(char *limiter, t_command *son)
{
	if (*limiter == '\"' || *limiter == '\'')
		return (without_expansions(limiter, son));
	else
		return (with_expansions(limiter, son));
}
