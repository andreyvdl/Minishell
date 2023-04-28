#include "../includes/minishell.h"

static char	*splitter(char *str, int flag)
{
	
	char	*splitter;
	int i;

	if (flag)
	{
		while (*str != '=')
			str++;
		splitter = str + 1;
		ft_putstr(splitter);
	}
	else
	{
		i = 0;
		while (str[i] != '=')
			i++;
		str[i] = '\0';
		splitter = str;
	}
	return (splitter);
}

void	export(char *str, t_hash *hash)
{
	while (str && (*str != ' ' &&  *str != '\t'))
		str++;
	while (str && (*str == ' ' || *str == '\t'))
		str++;
	char *reach;
	char *varible;

	varible = splitter(str, 0);
	reach = search(hash, varible);
	ft_putstr(varible);
	if (reach == NULL)
		insert_node(hash, varible, splitter(str, 1));
	else
		ft_putstr(reach);

}
