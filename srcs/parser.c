#include "../includes/minishell.h"

t_tokens	*new_token(e_token_type type, char *value, int len)
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
}