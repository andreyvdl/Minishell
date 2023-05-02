#include "../includes/minishell.h"

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

static void	double_quote_copy(char **str, char **new, t_hash *hash)
{
	*(*new)++ = *(*str)++;
	while (**str != '\"' && **str)
	{
		if (**str == '$')
			dollar_value(str, new, hash);
		else
			*(*new)++ = *(*str)++;
	}
	if (**str == '\"')
		*(*new)++ = *(*str)++;
}

static void	single_quote_copy(char **str, char **new)
{
	*(*new)++ = *(*str)++;
	while (**str != '\'' && **str)
		*(*new)++ = *(*str)++;
	if (**str == '\'')
		*(*new)++ = *(*str)++;
}

void	copy_with_expansions(char *str, char *new, t_hash *hash)
{
	while (*str)
	{
		if (*str == '\'')
			single_quote_copy(&str, &new);
		else if (*str == '\"')
			double_quote_copy(&str, &new, hash);
		else if (*str == '$')
			dollar_value(&str, &new, hash);
		else
			*new++ = *str++;
	}
}
