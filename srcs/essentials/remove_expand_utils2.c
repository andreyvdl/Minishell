#include "../../includes/minishell.h"

static void	aux_copy(char **new, char *value)
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

static void	expand_value_copy(char **new, char **str)
{
	size_t	len;
	char	*key;

	(*str)++;
	if (ft_isalpha(**str) == TRUE || **str == '_' || **str == '?')
	{
		if (**str == '?')
		{
			(*str)++;
			aux_copy(new, search(g_shell.hash, STATUS_CODE));
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) == TRUE || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		aux_copy(new, search(g_shell.hash, key));
		free(key);
	}
	else if (ft_isdigit(**str) == FALSE)// && (*str)++)
		aux_copy(new, "$");
	while (ft_isalnum(**str) == TRUE || **str == '_')
		(*str)++;
}

void	expand_copy(char *new, char *str)
{
	while (*str != '\0')
	{
		if (*str == '\"' || *str == '\'')
			str++;
		else if (*str == -1)
		{
			*new = '$';
			str++;
			new++;
		}
		else if (*str == '$')
			expand_value_copy(&new, &str);
		else
		{
			*new = *str;
			str++;
			new++;
		}
	}
}
