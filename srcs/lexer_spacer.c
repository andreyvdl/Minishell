#include "../includes/minishell.h"

int	metachar_and_quote_cases(char *str)
{
	if (ft_ismetachar(*(str + 1)) && !ft_ismetachar(*str) && *str != ' ')
		return (true);
	else if (ft_ismetachar(*str) && !ft_ismetachar(*(str + 1)) && \
	*(str + 1) != ' ' && *(str + 1) != '\0')
		return (true);
	else if ((*str == '|' && (*(str + 1) == '<' || *(str + 1) == '>')) || \
	((*str == '<' || *str == '>') && *(str + 1) == '|'))
		return (true);
	else if ((*(str + 1) == '\'' || *(str + 1) == '\"') && *str != ' ' && \
	!ft_isalnum(*str))
		return (true);
	return (false);
}

size_t	size_with_spaces(char *str)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			inside_quote_counter(&str, &counter, *str);
		else if (metachar_and_quote_cases(str))
			counter++;
		else
		{
			counter++;
			str++;
		}
	}
	return (counter);
}

void	copy_and_add_space(char *str, char **new)
{
	*(*new) = *str;
	(*new)++;
	*(*new) = ' ';
	(*new)++;
}

void	copy_2_new_str(char *str, char *new)
{
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			inside_quote_copy(&str, &new, *str);
		else if (metachar_and_quote_cases(str))
			copy_and_add_space(str, &new);
		else
		{
			*new = *str;
			new++;
			str++;
		}
	}
}

char	*separator(char *str)
{
	char	*new_str;
	size_t	size;

	size = size_with_spaces(str);
	new_str = (char *)ft_calloc((size + 1), sizeof(char));
	copy_2_new_str(str, new_str);
	free(str);
	return (new_str);
}
