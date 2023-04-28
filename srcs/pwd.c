#include "../includes/minishell.h"

void	pwd(char *str, t_hash *hash)
{
	while (*str && (*str != ' ' &&  *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	ft_putstr(str);
	ft_putchar('\n');
	(void)hash;
}
