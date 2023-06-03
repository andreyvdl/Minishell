#include "../../includes/minishell.h"

void	env()
{
	char	**env;
	int		i;

	i = 0;
	env = g_shell.envp;
	if (ft_matrixlen((const char **)g_shell.command->argv) > 1)
		return ((void)ft_printf("Command is: env!"));
	while (env && env[i])
		ft_printf("%s\n", env[i++]);
}
