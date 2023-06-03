#include "../../includes/minishell.h"

void	father_execute(void)
{
	if (ft_strcmp(g_shell.command[0].argv[0], "echo") == 0)
		return ;//father_echo(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "cd") == 0)
		return ;//father_cd(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "pwd") == 0)
		return ;//father_pwd(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "export") == 0)
		return ;//father_export(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "unset") == 0)
		return ;//father_unset(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "env") == 0)
		return ;//father_env(g_shell.command);
	else if (ft_strcmp(g_shell.command[0].argv[0], "exit") == 0)
		return ;//father_exit(g_shell.command);
}
