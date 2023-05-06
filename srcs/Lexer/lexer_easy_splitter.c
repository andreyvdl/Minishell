#include "../../includes/minishell.h"

static void	ignore_it(char **str, char quote)
{
	(*str)++;
	while (**str != quote && **str)
		(*str)++;
	if (**str)
		(*str)++;
}

void	easy_splitter(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
		{
			*str = -7;
			str++;
		}
		else if (*str == '\'' || *str == '\"')
			ignore_it(&str, *str);
		else
			str++;
	}
}
