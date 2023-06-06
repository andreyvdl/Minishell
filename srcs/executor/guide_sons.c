#include "../../includes/minishell.h"

static void	execute_cmd(size_t id)
{
	if (g_shell.command[id].argv != NULL && \
	isbuiltin(*g_shell.command[id].argv) == TRUE)
		builtins(g_shell.command[id].argv);
	else if (g_shell.command[id].argv != NULL && \
	*g_shell.command[id].argv != NULL)
		system_exec(g_shell.command[id].argv, g_shell.envp);
	else
	{
		free_son();
		exit(EXIT_SUCCESS);
	}
}

void	guide_sons(int *pipe, size_t id)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (g_shell.command[id].rd_here < STDIN_FILENO || \
	g_shell.command[id].wr_here < STDOUT_FILENO)
	{
		close(pipe[0]);
		close(pipe[1]);
		free_son();
		exit(EXIT_FAILURE);
	}
	open_redirect(pipe, id);
	close(pipe[0]);
	close(pipe[1]);
	execute_cmd(id);
}
