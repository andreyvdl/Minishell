#include "../includes/minishell.h"

static int	syntax_error(char *str)
{

	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str >= 33 && *str <= 126)
		return (-1);
	return (1);
}

void	pwd(char *str, t_hash *hash)
{
	if (syntax_error(str) == -1)
	{
		while (*str && (*str != ' ' && *str != '\t'))
			str++;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		ft_printf("pwd: bad option: %s\n", str);
	}
	else
		ft_printf("%s\n", search(hash, "PWD"));
}
