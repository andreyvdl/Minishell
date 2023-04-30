#include "../includes/minishell.h"

void	inside_quote_counter(char **str, size_t *counter, char quote)
{
	(*counter)++;
	(*str)++;
	while (**str && **str != quote)
	{
		(*counter)++;
		(*str)++;
	}
	if (**str == quote && ft_ismetachar(*(*str + 1)))
		(*counter)++;
}

void	inside_quote_copy(char **str, char **new, char quote)
{
	**new = **str;
	(*new)++;
	(*str)++;
	while (**str && **str != quote)
	{
		**new = **str;
		(*new)++;
		(*str)++;
	}
	**new = **str;
	(*new)++;
	if (**str == quote && ft_ismetachar(*(*str + 1)))
	{
		**new = ' ';
		(*new)++;
	}
}
