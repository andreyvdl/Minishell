#include "../../includes/minishell.h"


static int	validate_metachar(char **splited_pline)
{
	if (**splited_pline == '&')
	{
		ft_printf_fd(STDERR_FILENO, ERR_UNS_SYNTAX);
		return (TRUE);
	}
	else if (**splited_pline == '|')
	{
		if (pipe_case(splited_pline))
			return (TRUE);
	}
	else if (**splited_pline == '<')
	{
		if (read_from_case(splited_pline))
			return (TRUE);
	}
	else if (**splited_pline == '>')
	{
		if (write_to_case(splited_pline))
			return (TRUE);
	}
	return (FALSE);
}

static int	has_invalid_syntax(char **splited_pline)
{
	char	**temp;

	temp = splited_pline;
	while (*temp)
	{
		if (ft_ismetachar(**temp))
		{
			if (validate_metachar(temp))
				return (TRUE);
		}
		temp++;
	}
	return (FALSE);
}

static int	unclosed_quotes(char *pipeline)
{
	while (*pipeline)
	{
		if (*pipeline == '\'' || *pipeline == '\"')
		{
			if (unclosed_quotes_case(&pipeline, *pipeline))
				return (TRUE);
		}
		else
			pipeline++;
	}
	return (FALSE);
}

/*
TODO: separate the redirections from the pipeline before verify if they are
valid: bash accepts: `ls < gjabgja | cat > jgbahga` as two errors !!NOT ONE!!;
*/

int	parser(char *pipeline, t_hash *hash)
{
	char	**splited;

	easy_splitter(pipeline);
	if (unclosed_quotes(pipeline))
	{
		insert_node(hash, "?", "2");
		return (TRUE);
	}
	splited = ft_split(pipeline, -7);
	if (has_invalid_syntax(splited))
	{
		ft_free_matrix((void **)splited);
		insert_node(hash, "?", "2");
		return (TRUE);
	}
	// if (redirect_invalid(splited, hash))
	// {
	// 	ft_free_matrix((void **)splited);
	// 	insert_node(hash, "?", "1");
	// 	return (TRUE);
	// }
	// execute_line(expand_vars(pipeline, hash), hash);
	// ft_printf("\n");
	ft_free_matrix((void **)splited);
	return (FALSE);
}
