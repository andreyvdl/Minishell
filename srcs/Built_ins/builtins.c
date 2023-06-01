#include "../../includes/minishell.h"

void	builtins()
{
	if (ft_strcmp(g_shell.command->argv[0], "cd") == 0)
		cd();
	else if (ft_strcmp(g_shell.command->argv[0], "echo") == 0)
		echo();
	else
		ft_printf("builtin");
}