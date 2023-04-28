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

static int	occurrence(char *str, char c, t_hash *hash, int flag)
{
	int	j;

	if (*str == c)
	{
		j = 1;
		while (str[j])
		{
			if (str[j] == c)
			{
				if (flag)
					ft_putchar('\n');
				return (1);
			}
			if (str[j] == '$' && c == '"')
				j += get_variable(str + j + 1, hash);
			else
				ft_putchar(str[j]);
			j++;
		}
	}
	return (0);
}
 void trace_on(char *str, t_hash *hash)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] && str[i] == 'n')
        i++;

    if (str[i] && (str[i] == ' ' || str[i] == '\t'))
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;

        if (str[i] == '"' || str[i] == '\'')
        {
            occurrence(str + i, '"', hash, 0);
            occurrence(str + i, '\'', hash, 0);
        }
        else
        {
            ft_putstr(str + i);
        }
    }
    else
    {
        while (str[i] && str[i] != '\'' && str[i] != '"')
            i++;

        if (str[i] == '"' || str[i] == '\'')
        {
            occurrence(str + i, '"', hash, 0);
            occurrence(str + i, '\'', hash, 0);
        }
        else
        {
            ft_putstr(str);
        }
    }
}


void	echo(char *str, t_hash *hash)
{
	while ((*str == ' ' || *str == '\t'))
		str++;
	while ((*str != ' ' && *str != '\t'))
		str++;
	while ((*str == ' ' || *str == '\t'))
		str++;
	if (ft_strncmp("-n", str, 2) == 0)
		trace_on(str, hash);
	else
	{
		occurrence(str, '"', hash, 1);
		occurrence(str, '\'', hash, 1);
	}
}