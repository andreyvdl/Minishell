#include "../includes/minishell.h"

int	cd(char *str)
{
	while (*str && (*str != ' ' &&  *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}
