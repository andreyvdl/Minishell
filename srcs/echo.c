#include "../includes/minishell.h"

static char	*splitter(char *str)
{
	int		j;
	int		i;
	char	*splitter;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && \
	str[i] != '"')
		i++;
	splitter = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && \
	str[i] != '"')
		splitter[i++] = str[j++];
	splitter[i] = '\0';
	return (splitter);
}


static int	get_variable(char *str, t_hash *hash)
{
	char	*value;

	value = splitter(str);
	ft_putstr(search(hash, value));
	return (ft_strlen(value));
}


static int	occurrence(char *str, char c, t_hash *hash)
{
	int	j;

	if (*str == c)
	{
		j = 1;
		while (str[j])
		{
			if (str[j] == c)
				return (1);
			if (str[j] == '$' && c == '"')
				j += get_variable(str + j + 1, hash);
			else
				ft_putchar(str[j]);
			j++;
		}
	}
	return (0);
}


void	echo(char *str, t_hash *hash)
{
	while (*str != ' ' && *str != '\t')
		str++;
	str++;
	if (occurrence(str, '"', hash) == 0)
		ft_putchar('\n');
	else if (occurrence(str, '\'', hash) == 0)
		ft_putchar('\n');
}
