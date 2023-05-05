#include "../includes/minishell.h"

static void	get_dollar_value_size(char **str, size_t *counter, t_hash *hash)
{
	char	*key;

	(*str)++;
	key = (*str);
	if (!(*key >= '0' && *key <= '9'))
	{
		if (*key == '?')
		{
			(*counter) += ft_strlen(search(hash, "?"));
			(*str)++;
			return ;
		}
		while (ft_isalnum(*key) || *key == '_')
			key++;
		key = ft_substr(*str, 0, key - *str);
		(*counter) += ft_strlen(search(hash, key));
		free(key);
	}
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
			get_dollar_value_size(str, counter, hash);
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
			get_dollar_value_size(&str, &counter, hash);
		else
		{
			counter++;
			str++;
		}
	}
	return (counter);
}

char	*expand_vars(char *str, t_hash *hash)
{
	char	*expanded_str;
	size_t	size;

	if (ft_strchr(str, '$'))
	{
		size = size_with_values(str, hash);
		expanded_str = (char *)ft_calloc((size + 1), sizeof(char));
		copy_with_expansions(str, expanded_str, hash);
		return (expanded_str);
	}
	else
		return (str);
}
