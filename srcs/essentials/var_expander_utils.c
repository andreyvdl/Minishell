#include "../../includes/minishell.h"

size_t	get_value_size(char **str)
{
	char	*key;
	size_t	len;

	(*str)++;
	if (ft_isdigit(**str) == FALSE)
	{
		if (**str == '?')
		{
			(*str)++;
			return (ft_strlen(search(g_shell.hash, "?")));
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		*str += len;
		len = ft_strlen(search(g_shell.hash, key));
		free(key);
		return (len);
	}
	while (ft_isalnum(**str) || **str == '_')
		(*str)++;
	return (0);
}

static void	strcpy_increment(char **dst, char *src)
{
	if (src == NULL)
		return ;
	while (*src != '\0')
	{
		**dst = *src;
		(*dst)++;
		src++;
	}
}

void	copy_value(char **old, char **new)
{
	char	*key;
	size_t	len;

	(*old)++;
	if (ft_isdigit(**old) == FALSE)
	{
		if (**old == '?')
		{
			(*old)++;
			strcpy_increment(new, search(g_shell.hash, "?"));
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*old + len)) || *(*old + len) == '_')
			len++;
		key = ft_substr(*old, 0, len);
		*old += len;
		strcpy_increment(new, search(g_shell.hash, key));
		free(key);
		return ;
	}
	while (ft_isalnum(**old) || **old == '_')
		(*old)++;
}
