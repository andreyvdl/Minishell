#include "../../includes/minishell.h"

void	pre_executor(void)
{
	if (g_shell.nbr_sons == 1 && g_shell.command->argv != NULL)
	{
		if (isbuiltin(g_shell.command->argv[0]) == TRUE)
			father_execute();
		else
			executor();
	}
	else
		executor();
}
