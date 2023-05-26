#include "../../includes/minishell.h"

static size_t	size_with_values(char *str)
{
	size_t	size;

	size = 0;
	while (*str != '\0')
	{
		if (*str == '$')
			size += get_value_size(&str);
		else
		{
			str++;
			size++;
		}
	}
}

static void	copy_with_values(char *old, char *new)
{
	while (*old != '\0')
	{
		if (*old == '$')
			copy_value(&old, &new);
		else
		{
			*new = *old;
			old++;
			new++;
		}
	}
}

static void	search_replace(char *str, char find, char put)
{
	while (*str != '\0')
	{
		if (*str == find)
			*str = put;
		str++;
	}
}

char	*var_expander(char *str)
{
	char	*expanded_str;
	size_t	size;

	if (ft_strchr(str, '$'))
	{
		size = size_with_values(str);
		expanded_str = (char *)ft_calloc((size + 1), sizeof(char));
		copy_with_values(str, expanded_str);
		search_replace(expanded_str, -1, '$');
		return (expanded_str);
	}
	else
	{
		search_replace(str, -1, '$');
		return (str);
	}
}
