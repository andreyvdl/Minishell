#include "../../includes/minishell.h"

/* static void	pass_quotes(char **input, char quote)
{
	(*input)++;
	while (**input != quote)
		(*input)++;
}

static void	count_cmds(char *input, size_t *n_cmds)
{
	(*n_cmds)++;
	while (*input)
	{
		if (*input == '|')
			(*n_cmds)++;
		else if (*input == '\'' || *input == '\"')
			pass_quotes(&input, *input);
		input++;
	}
}

// TODO: make this function cut part of the command: `ls-7-la-7|-7echo-7oi`
// to: `ls-7-la` and `echo-7oi`

static char	*extract_cmd(char **input)
{
	char	*cmd;
	char	*temp;

	temp = *input;
	while (**)
}

static char	**count_and_fill(char *input, size_t *n_cmds)
{
	char	**commands;
	size_t	index;

	count_cmds(input, n_cmds);
	commands = (char **)ft_calloc((*n_cmds) + 1, sizeof(char *));
	index = 0;
	while (index < (*n_cmds))
	{
		commands[index] = extract_cmd(&input);
		index++;
	}
}

void	tokenizer(char *input, t_hash *hash)
{
	char	**commands;
	size_t	n_cmds;

	n_cmds = 0;
	commands = count_and_fill(input, &n_cmds);
} */
