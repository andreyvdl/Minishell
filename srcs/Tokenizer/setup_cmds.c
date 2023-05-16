#include "../../includes/minishell.h"

pid_t	set_up_multiple_cmd(char *cmd, t_hash *hash)
{
	t_pipe	*pipe;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{

	}
}
