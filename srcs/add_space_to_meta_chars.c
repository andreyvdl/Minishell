#include "../includes/minishell.h"

int	ft_ismetachar(int c)
{
	if (c == '|' || c == '<' || c == '>' || c == '&')
		return (true);
	return (false);
}

size_t	size_with_spaces(char *str)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		if (ft_ismetachar(*(str + 1)) && !ft_ismetachar(*str) && *str != ' ')
			counter++;
		else if (ft_ismetachar(*str) && !ft_ismetachar(*(str + 1)) && \
		*(str + 1) != ' ' && *(str + 1) != '\0')
			counter++;
		else if ((*str == '|' && (*(str + 1) == '<' || *(str + 1) == '>')) || \
		((*str == '<' || *str == '>') && *(str + 1) == '|'))
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
		if (ft_ismetachar(*(str + 1)) && !ft_ismetachar(*str) && *str != ' ')
			copy_and_add_space(str, &new);
		else if (ft_ismetachar(*str) && !ft_ismetachar(*(str + 1)) && \
		*(str + 1) != ' ' && *(str + 1) != '\0')
			copy_and_add_space(str, &new);
		else if ((*str == '|' && (*(str + 1) == '<' || *(str + 1) == '>')) || \
		((*str == '<' || *str == '>') && *(str + 1) == '|'))
			copy_and_add_space(str, &new);
		else
		{
			*new = *str;
			new++;
		}
		str++;
	}
	*new = '\0';
}

void	separator(char *str)
{
	size_t	size = size_with_spaces(str);
	char	*new_str = (char *)malloc(size + 1);

	copy_2_new_str(str, new_str);
	printf("ORIGINAL[%s]\nDEPOIS[%s]\n", str, new_str);
	free(new_str);
}
/*
int	main(void) {
	char	*str = "<<<<<<<>>>>>>|>>|<<";
	char	*str_teste = (char *)malloc(ft_strlen(str) + 1);
	size_t	i = 0;

	while (str[i]) {
		str_teste[i] = str[i];
		i++;
	}
	str_teste[i] = '\0';
	separator(str_teste);
	free(str_teste);
}
*/
