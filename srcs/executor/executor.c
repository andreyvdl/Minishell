#include "../../includes/minishell.h"

/* static char **bins_path()
{
	return (ft_split(search(g_shell.hash, "PATH"), ':'));
}

static char **concat_bar()
{
	char	**bin;
	char	*path;
	int		i;


	bin = bins_path();
	i = 0;
	while (bin && bin[i])
	{
		if (!(bin[i][ft_strlen(bin[i]) - 1] == '/'))
		{
			path = ft_strjoin(bin[i], "/");
			free(bin[i]);
			bin[i] = path;
		}
		i++;
	}
	bin[i] = NULL;
	return (bin);
}

static char	**path_creator(char *command)
{
	char	**bin;
	char	*path;
	int		i;

	bin = concat_bar();
	i = 0;
	while (bin && bin[i])
	{
		path = ft_strjoin(bin[i], command);
		free(bin[i]);
		bin[i]= path;
		i++;
	}
	bin[i] = NULL;
	return (bin);
}

static	void	runtime(char **bins)
{
	pid_t	pid;
	int		executed;
	size_t		i;

	i = 0;
	executed = 0;
	while (bins && *bins)
	{
		if (access((*bins), X_OK) == 0 && !executed)
		{
			executed = 1;
			pid = fork();
			if (pid == 0)
			{
				if (execve((*bins), g_shell.command->argv, g_shell.envp) == -1)
					perror("execvp");
				exit(0);
			}
			else if (pid < 0)
				perror("fork");
			else
			{
				while (i++ < g_shell.nbr_sons)
					wait(NULL);
			}
		}
		bins++;
	}
} */

static void	status_after_execution(int status)
{
	char	*nbr;

	nbr = ft_itoa(status);
	insert_node(g_shell.hash, "?", nbr);
	free(nbr);
}

static void	wait_for_them(pid_t pid, int *pipe)
{
	int	status;

	close(pipe[0]);
	close(pipe[1]);
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

void	executor()
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror(ERR_PIPE);
		return ;
	}
	while (g_shell.id < g_shell.nbr_sons)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(ERR_FORK);
			kill(0, SIGKILL);
			return ;
		}
		if (pid == 0)
			guide_sons(pipe_fd, g_shell.id);
		g_shell.id++;
	}
	wait_for_them(pid, pipe_fd);
}
