#include "../includes/minishell.h"

static char *splitter(char *str)
{
	int j;
	int i;
	char *splitter;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '\t')
		j++;
	splitter = (char *)malloc(sizeof(char) * (j - i + 1));
	j = -1;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		splitter[++j] = str[i++];
	splitter[j + 1] = '\0';
	return (splitter);
}


static int get_variable(char *str, t_hash *hash)
{
	char *value = splitter(str);

	printf(search(hash, value));
	return (1);
}


static int	occurrence(char *str, char c, t_hash *hash)
{
	int j;

	if (*str == c)
	{
		j = 1;
		while (str[j])
		{
			if (str[j] == c)
				return (1);
			if (str[j] == '$')
				j += get_variable(str + j + 1, hash);
			j++;
		}
	}
	return (0);
}


void	echo(char *str, t_hash *hash)
{
	while (*str)
	{	
		if (occurrence(str, '"', hash))
			ft_putchar('\n');
		else if (occurrence(str, '\'', hash))
			ft_putchar('\n');
		str++;
	}
}
