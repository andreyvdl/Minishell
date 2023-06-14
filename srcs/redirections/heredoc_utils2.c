#include "../../includes/minishell.h"

static void	copy_this_value(char **new, char *value)
{
	size_t	index;

	if (value == NULL)
		return ;
	index = 0;
	while (value[index] != '\0')
	{
		**new = value[index];
		(*new)++;
		index++;
	}
}

static void	dollar_value(char **str, char **new, t_hash *hash)
{
	char	*key;
	size_t	len;

	(*str)++;
	if (ft_isalpha(**str) == TRUE || **str == '_' || **str == '?')
	{
		if (**str == '?')
		{
			copy_this_value(new, search(hash, STATUS_CODE));
			(*str)++;
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		copy_this_value(new, search(hash, key));
		free(key);
	}
	else if (ft_isdigit(**str) == FALSE && (*str)++)
		copy_this_value(new, "$");
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
	size_t	len;

	(*str)++;
	if (ft_isalpha(**str) == TRUE || **str == '_' || **str == '?')
	{
		if (**str == '?')
		{
			(*counter) += ft_strlen(search(hash, STATUS_CODE));
			(*str)++;
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		(*counter) += ft_strlen(search(hash, key));
		free(key);
	}
	else if (ft_isdigit(**str) == FALSE)
		(*counter)++;
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
