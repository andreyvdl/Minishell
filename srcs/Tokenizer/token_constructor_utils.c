#include "../../includes/minishell.h"

static void	pass_quotes(char **input, char quote)
{
	(*input)++;
	while (**input != quote)
		(*input)++;
}

void	count_cmds(char *input, size_t *n_cmds)
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

static char	*clean_cmd(char *cmd)
{
	char	set[1];
	char	*clean;

	set[0] = -7;
	set[1] = '\0';
	clean = ft_strtrim(cmd, set);
	free(cmd);
	return (clean);
}

char	*extract_cmd(char **input)
{
	char	*cmd;
	char	*temp;

	temp = input;
	while (**input && **input != '|')
	{
		if (**input == '\'' || **input == '\"')
			pass_quotes(input, **input);
		(*input)++;
	}
	cmd = ft_substr(temp, 0, (*input) - temp);
	if (**input)
		(*input)++;
	return (clean_cmd(cmd));
}
