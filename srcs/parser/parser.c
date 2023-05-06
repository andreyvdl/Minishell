#include "../../includes/minishell.h"


static int	validate_metachar(char **splited_pline)
{
	if (**splited_pline == '&')
	{
		ft_putendl_fd("\e[31mms: unsuported syntax `&`\e[0m", 2);
		return (true);
	}
	else if (**splited_pline == '|')
	{
		if (pipe_case(splited_pline))
			return (true);
	}
	else if (**splited_pline == '<')
	{
		if (read_from_case(splited_pline))
			return (true);
	}
	else if (**splited_pline == '>')
	{
		if (write_to_case(splited_pline))
			return (true);
	}
	return (false);
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
				return (true);
		}
		temp++;
	}
	return (false);
}

static int	unclosed_quotes(char *pipeline)
{
	while (*pipeline)
	{
		if (*pipeline == '\'' || *pipeline == '\"')
		{
			if (unclosed_quotes_case(&pipeline, *pipeline))
				return (true);
		}
		else
			pipeline++;
	}
	return (false);
}

int	parser(char *pipeline, t_hash *hash)
{
	char	**splited;

	if (unclosed_quotes(pipeline))
	{
		insert_node(hash, "?", "2");
		return (true);
	}
	splited = ft_split(pipeline, -7);
	if (has_invalid_syntax(splited))
	{
		ft_free_matrix((void **)splited);
		insert_node(hash, "?", "2");
		return (true);
	}
	ft_free_matrix((void **)splited);
	return (false);
}
