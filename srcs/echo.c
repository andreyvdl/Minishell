#include "../includes/minishell.h"

void	echo(char *str, t_hash *hash)
{
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	(void)hash;
	ft_putstr(expand_vars(str, hash));
}