#include "../../includes/minishell.c"

static void	copy_this_value(char **new, char *value)
{
	size_t	len;

	len = ft_strlen(value);
	ft_memcpy(*new, value, len);
	(*new) = (*new) + len;
}

static void	dollar_value(char **str, char **new, t_hash *hash)
{
	char	*key;
	char	*value;

	(*str)++;
	key = (*str);
	if (!(*key >= '0' && *key <= '9'))
	{
		if (*key == '?')
		{
			value = search(hash, "?");
			copy_this_value(new, value);
			(*str)++;
			return ;
		}
		while (ft_isalnum(*key) || *key == '_')
			key++;
		key = ft_substr(*str, 0, key - *str);
		value = search(hash, key);
		free(key);
		copy_this_value(new, value);
	}
	while ((ft_isalnum(**str) || **str == '_') && **str)
		(*str)++;
}


void	copy_with_expansions_heredoc(char *str, char *new, t_hash *hash)
{
	while (*str)
	{
		if (*str == '$')
			dollar_value(&str, &new, hash);
		else
			*new++ = *str++;
	}
}

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

size_t	size_with_values_heredoc(char *str, t_hash *hash)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		if (*str == '$')
			get_dollar_value_size(&str, &counter, hash);
		else
		{
			counter++;
			str++;
		}
	}
	return (counter);
}
