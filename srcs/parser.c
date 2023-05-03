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

	// https://www.phind.com/search?cache=ee788b8e-bdf8-4d7c-adb2-9754bd0036e1&init=true
	temp = splited_pline;
	while (*splited_pline)
	{
		if (ft_ismetachar(**splited_pline))
		{
			if (validate_metachar(splited_pline))
			{
				// ft_free_matrix((void ***)&temp); -- segfault, mas precisa de free
				return (true);
			}
		}
		splited_pline++;
	}
	// ft_free_matrix((void ***)&temp); -- segfault, mas precisa de free
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
	if (temp != pipeline) // se o endereço das duas for igual significa q n tem $
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
	// printf("[%s]\n", pipeline);
}

/* t_tokens	*new_token(e_token_type type, char *value, int len)
{
	t_tokens *token;

	token = (t_tokens *)malloc(sizeof(t_tokens));
	token->type = type;
	token->value = value;
	token->len = len;
	token->next = NULL;
	return (token);
}

void	add_token(t_tokens **tokens, t_tokens *new_token)
{
	t_tokens *current;

	current = *tokens;
	if (current == NULL)
		*tokens = new_token;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_token;
	}
}

// Verifica se um comando e valido comparando o comando como (echo, cd, pwd, exit, export, unset e env).
int		is_valid_command(char *command)
{
	char	**commands;
	char	*com;
	int		i;

	i = 0;
	com = "echo cd pwd exit export unset env";
	commands = ft_split(com, ' ');
	while (commands[i])
	{
		if (ft_strcmp(command, commands[i]) == 0)
			return (1);
		i++;
	}
	free(commands);
	return (0);
}

// Faz a analise usando o separator  ele divide o input em tokens (palavras, comandos e caracteres especiais)
t_tokens *parsing(char *input)
{
	t_tokens *tokens;
	char	*str;
	char	*value;

	tokens = NULL;
	str = separator(input);
	while (*str && str)
	{
		if (ft_isspace(*str))
		{
			if (*(str + 1) && !ft_ismetachar(*(str + 1)))
				value = ft_strjoin(value, " ");
			str++;
		}
		else if (ft_ismetachar(*str))
		{
			value = (char *)malloc(sizeof(char) * 2);
			value[0] = *str;
			value[1] = '\0';
			add_token(&tokens, new_token(META_CHAR, value, ft_strlen(value)));
			str++;
		}
		else
		{
			value = str;
			while (*str && str && !ft_isspace(*str) && !ft_ismetachar(*str))
				str++;
			if (*str && str)
			{
				*str = '\0';
				str++;
			}
			if (is_valid_command(value))
				add_token(&tokens, new_token(COMMAND, value, ft_strlen(value)));
			else
				add_token(&tokens, new_token(WORD, value, ft_strlen(value)));
		}
	}
	return (tokens);
}

void parser(char *input, t_hash *hash)
{
	t_tokens *tokens;
	t_tokens *current;
	(void)hash;
	tokens = parsing(input);
	current = tokens;
	while (current)
	{
		if (current->type == META_CHAR && current->value[0] == '|')
			ft_printf("\n");
		ft_printf("type: %d; value: %s\n", current->type, current->value);
		current = current->next;
	}
	ft_printf("\n");
} */
