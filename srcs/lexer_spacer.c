#include "../includes/minishell.h"

int	meta_char_n_quote_cases(char *str)
{
	if (ft_ismetachar(*(str + 1)) && !ft_ismetachar(*str) && *str != ' ')
		return (true);
	else if (ft_ismetachar(*str) && !ft_ismetachar(*(str + 1)) && \
	*(str + 1) != ' ' && *(str + 1) != '\0')
		return (true);
	else if ((*str == '|' && (*(str + 1) == '<' || *(str + 1) == '>')) || \
	((*str == '<' || *str == '>') && *(str + 1) == '|'))
		return (true);
	else if ((*(str + 1) == '\'' || *(str + 1) == '\"') && *str != ' ')
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
		else if (meta_char_n_quote_cases(str))
			counter++;
		counter++;
		str++;
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
		else if (meta_char_n_quote_cases(str))
			copy_and_add_space(str, &new);
		else
		{
			*new = *str;
			new++;
		}
		str++;
	}
}

char	*separator(char *str)
{
	char	*new_str;
	size_t	size;

	size = size_with_spaces(str);
	new_str = malloc(sizeof(char) * (size + 1));
	new_str[size] = '\0';
	copy_2_new_str(str, new_str);
	return (new_str);
}
