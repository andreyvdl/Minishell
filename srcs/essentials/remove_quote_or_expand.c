#include "../../includes/minishell.h"

static void	remove_quote(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\'')
		{
			ft_memmove(str, str + 1, ft_strlen(str) + 1);
			while (*str != '\'')
				str++;
			ft_memmove(str, str + 1, ft_strlen(str) + 1);
		}
		else if (*str == '\"')
		{
			ft_memmove(str, str + 1, ft_strlen(str) + 1);
			while (*str != '\"')
				str++;
			ft_memmove(str, str + 1, ft_strlen(str) + 1);
		}
		else
			str++;
	}
}

static char	*solo_expand(char *str)
{
	char	*new;

	new = (char *)ft_calloc(solo_size(str) + 1, sizeof(char));
	solo_copy(new, str);
	free(str);
	return (new);
}

static char	*remove_expand(char *str)
{
	char	*new;

	new = (char *)ft_calloc(expand_size(str) + 1, sizeof(char));
	expand_copy(new, str);
	free(str);
	return (new);
}

char	*remove_quote_or_expand(char *str)
{
	if ((ft_strchr(str, '\'') || ft_strchr(str, '\"')) && ft_strchr(str, '$'))
		return (remove_expand(str));
	else if (ft_strchr(str, '$'))
		return (solo_expand(str));
	else if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		remove_quote(str);
	return (str);
}
