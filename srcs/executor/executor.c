#include "../../includes/minishell.h"

static void	status_after_execution(int status)
{
	char	*nbr;

	nbr = ft_itoa(status);
	insert_node(g_shell.hash, STATUS_CODE, nbr);
	free(nbr);
}

static void	wait_for_them(pid_t pid)
{
	int	status;

	waitpid(pid, &status, NONE);
	while (g_shell.id > 1)
	{
		wait(NULL);
		g_shell.id--;
	}
	if (WIFEXITED(status))
		status_after_execution(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		status_after_execution(WTERMSIG(status) + 128);
}

static int	forking(pid_t *pid, int *pipe, int fd_original)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror(ERR_FORK);
		kill(0, SIGKILL);
		return (EXIT_FAILURE);
	}
	if (*pid == 0)
	{
		close(fd_original);
		guide_sons(pipe, g_shell.id);
	}
	return (EXIT_SUCCESS);
}

void	executor()
{
	int		pipe_fd[2];
	int		backup_fd;
	pid_t	pid;

	backup_fd = dup(STDIN_FILENO);
	while (g_shell.id < g_shell.nbr_sons)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror(ERR_PIPE);
			status_after_execution(EXEC_WENT_WRONG);
			return ;
		}
		if (forking(&pid, pipe_fd, backup_fd) == EXIT_FAILURE)
			break ;
		close(STDIN_FILENO);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		g_shell.id++;
	}
	dup2(backup_fd, STDIN_FILENO);
	close(backup_fd);
	wait_for_them(pid);
}
