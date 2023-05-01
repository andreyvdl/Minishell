#include "../includes/minishell.h"


static void	get_value_dollar_size(char **str, size_t *counter, t_hash *hash)
{
	char	*key;

	(*str)++;
	key = (*str);
	if (*key >= '0' && *key <= '9')
	{
		while ((ft_isalnum(**str) || **str == '_') && **str)
			(*str)++;
		return ;
	}
	else if (*key == '?')
	{
		(*counter) += ft_strlen(search(hash, "?"));
		(*str) = (*str) + 2;
		return ;
	}
	while (ft_isalnum(*key) || *key == '_')
		key++;
	key--;
	key = ft_substr(*str, 0, key - *str);
	(*counter) += ft_strlen(search(hash, key));
	free(key);
	while ((ft_isalnum(**str) || **str == '_') && **str)
		(*str)++;
}

static void	get_value_size_double(char **str, size_t *counter, t_hash *hash)
{
	(*str)++;
	(*counter)++;
	while (**str != '\"' && **str)
	{
		if (**str == '$')
			get_value_dollar_size(str, counter, hash);
		else
		{
			(*str)++;
			(*counter)++;
		}
	}
	if (**str == '\"')
	{
		(*str)++;
		(*counter)++;
	}
}

static void	single_quote_size(char **str, size_t *counter)
{
	(*str)++;
	(*counter)++;
	while (**str != '\'' && **str)
	{
		(*str)++;
		(*counter)++;
	}
	if (**str == '\'')
	{
		(*str)++;
		(*counter)++;
	}
}

static size_t	size_with_values(char *str, t_hash *hash)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		if (*str == '\'')
			single_quote_size(&str, &counter);
		else if (*str == '\"')
			get_value_size_double(&str, &counter, hash);
		else if (*str == '$')
			get_value_dollar_size(&str, &counter, hash);
		else
		{
			counter++;
			str++;
		}
	}
	// coloquei para para o erro de n retornar nada 
	return (counter);
}

static char	*expand_it(char *str, t_hash *hash)
{
	char	*new_cmd;
	size_t	size;

	size = size_with_values(str, hash);
	new_cmd = malloc(size + 1);
	new_cmd[size] = '\0';
	//copy_with_values(str, new_cmd);
	return (new_cmd);
}

char	*expand_vars(char *str, t_hash *hash)
{
	char	*expanded_str;

	if (ft_strchr(str, '$'))
	{
		expanded_str = expand_it(str, hash);
		free(str);
		return (expanded_str);
	}
	else
		return (str);
}

/*
Se a variavel comecar com numero eh invalida entao n vai pra conta e a string fica sem o $nome
Se ela for ? o que vier depois do ? fica concatenado entao $?oi fica 0oi
Se n for nenhum caso ela eh normal entao $HOME fica /home/usr
*/