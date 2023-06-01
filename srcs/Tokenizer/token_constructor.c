#include "../../includes/minishell.h"

static char	**count_and_fill(char *input, size_t *nbr_cmds)
{
	char	**commands;
	size_t	index;

	count_cmds(input, nbr_cmds);
	commands = (char **)ft_calloc((*nbr_cmds) + 1, sizeof(char *));
	index = 0;
	while (index < (*nbr_cmds))
	{
		commands[index] = extract_cmd(&input);
		index++;
	}
	commands[index] = NULL;
	return (commands);
}

void	tokenizer(char *input, t_hash *hash)
{
	char	**commands;
	size_t	nbr_cmds;

	nbr_cmds = 0;
	commands = count_and_fill(input, &nbr_cmds);
	free(input);
	if (set_up_global(commands, nbr_cmds, hash) == FALSE)
	{
		executor();
	 	ft_free_matrix((void **)commands);
		return ;
	}
	else
		ft_free_matrix((void **)commands);
}