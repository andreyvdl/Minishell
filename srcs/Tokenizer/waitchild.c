#include "../../includes/minishell.h"

void	wait_child(pid_t pid, size_t n_cmds)
{
	int		wstatus;
	size_t	count;

	count = 1;
	waitpid(pid, &wstatus, 0);
	while (count < n_cmds)
	{
		wait(NULL);
		count++;
	}
}