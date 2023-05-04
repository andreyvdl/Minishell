#include "../includes/minishell.h"


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
	while (*splited_pline)
	{
		if (ft_ismetachar(**splited_pline))
		{
			if (validate_metachar(splited_pline))
			{
				ft_free_matrix((void ***)&temp);
				return (true);
			}
		}
		splited_pline++;
	}
	ft_free_matrix((void ***)&temp);
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

static char	*lexer(char *pipeline, t_hash *hash)
{
	char	*temp;

	temp = separator(pipeline);
	free(pipeline);
	pipeline = NULL;
	easy_splitter(temp);
	pipeline = expand_vars(temp, hash);
	if (temp != pipeline)
		free(temp);
	return (pipeline);
}

void	parser(char *pipeline, t_hash *hash)
{
	pipeline = lexer(pipeline, hash);
	if (unclosed_quotes(pipeline))
	{
		free(pipeline);
		insert_node(hash, "?", "2");
		return ;
	}
	if (has_invalid_syntax(ft_split(pipeline, -7)))
	{
		free(pipeline);
		insert_node(hash, "?", "2");
		return ;
	}
	ft_printf("[%s]\n", pipeline);
}
