#include "../../includes/minishell.h"

static void	execute_cmd(size_t id)
{
	if (g_shell.command[id].argv != NULL && \
	isbuiltin(*g_shell.command[id].argv) == TRUE)
		exit(builtins(g_shell.command[id].argv));
	else if (g_shell.command[id].argv != NULL && \
	*g_shell.command[id].argv != NULL)
		system_exec(g_shell.command[id].argv, g_shell.envp, id);
	else
	{
		free_son();
		if (g_shell.command[id].argv != NULL)
			ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, \
			*g_shell.command[id].argv);
		else
			ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, NULL);
		exit(CMD_NOT_FOUND);
	}
}

void	guide_sons(int *pipe, size_t id)
{
	if (g_shell.command[id].rd_here < STDIN_FILENO || \
	g_shell.command[id].wr_here < STDOUT_FILENO)
	{
		close(pipe[0]);
		close(pipe[1]);
		free_son();
		exit(FILE_ERROR);
	}
	if (dup2(pipe[0], g_shell.command[id].rd_here) == -1 || \
	dup2(pipe[1], g_shell.command[id].wr_here) == -1) // 2 instruções em uma linha??????????????
	{
		perror(ERR_DUP);
		close(pipe[0]);
		close(pipe[1]);
		free_son();
		exit(FILE_ERROR);
	}
	close(pipe[0]);
	close(pipe[1]);
	execute_cmd(id);
}
