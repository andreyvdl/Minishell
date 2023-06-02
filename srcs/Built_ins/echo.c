#include "../../includes/minishell.h"

int	echo()
{
	char	**str;
	int		i;

	str = g_shell.command->argv;
	if (str[1] == NULL)
		return ((void)ft_printf("\n"));
	else if (ft_strcmp(str[1], "-n") == 0)
	{
		i = 2;
		while (str && str[i])
			ft_printf("%s ", str[i++]);
		return;
	}
	i = 1;
	while (str && str[i])
			ft_printf("%s ", str[i++]);
	ft_putchar('\n');
}
