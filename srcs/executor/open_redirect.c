#include "../../includes/minishell.h"

static void	pipe_error(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	free_son();
	perror(ERR_DUP_2);
	exit(EXEC_WENT_WRONG);
}

static void	open_last(int *pipe, size_t id)
{
	if (g_shell.command[id].rd_here > STDIN_FILENO)
	{
		if (dup2(g_shell.command[id].rd_here, STDIN_FILENO) == -1)
			pipe_error(pipe);
	}
	if (g_shell.command[id].wr_here > STDOUT_FILENO)
		if (dup2(g_shell.command[id].wr_here, STDOUT_FILENO) == -1)
			pipe_error(pipe);
}

static void	open_first(int *pipe, size_t id)
{
	if (g_shell.command[id].rd_here > STDIN_FILENO)
	{
		if (dup2(g_shell.command[id].rd_here, STDIN_FILENO) == -1)
			pipe_error(pipe);
	}
	if (g_shell.command[id].wr_here > STDOUT_FILENO)
	{
		if (dup2(g_shell.command[id].wr_here, STDOUT_FILENO) == -1)
			pipe_error(pipe);
	}
	else
		if (dup2(pipe[1], STDOUT_FILENO) == -1)
			pipe_error(pipe);
}

static void	open_middle(int *pipe, size_t id)
{
	if (g_shell.command[id].rd_here > STDIN_FILENO)
	{
		if (dup2(g_shell.command[id].rd_here, STDIN_FILENO) == -1)
			pipe_error(pipe);
	}
	if (g_shell.command[id].wr_here > STDOUT_FILENO)
	{
		if (dup2(g_shell.command[id].wr_here, STDOUT_FILENO) == -1)
			pipe_error(pipe);
	}
	else
		if (dup2(pipe[1], STDOUT_FILENO) == -1)
			pipe_error(pipe);
}

void	open_redirect(int *pipe, size_t id)
{
	if (id == 0 && g_shell.nbr_sons == 1)
	{
		if (g_shell.command[id].rd_here > STDIN_FILENO)
			if (dup2(g_shell.command[id].rd_here, STDIN_FILENO) == -1)
				pipe_error(pipe);
		if (g_shell.command[id].wr_here > STDOUT_FILENO)
			if (dup2(g_shell.command[id].wr_here, STDOUT_FILENO) == -1)
				pipe_error(pipe);
	}
	else if (id > 0 && id == g_shell.nbr_sons - 1)
		open_last(pipe, id);
	else if (id == 0 && g_shell.nbr_sons > 1)
		open_first(pipe, id);
	else
		open_middle(pipe, id);
}
