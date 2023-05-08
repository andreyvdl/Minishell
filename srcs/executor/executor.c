#include "../includes/minishell.h"

char *find_executable(char *command, t_hash *hash)
{
	char *path;
	char **dirs;
	char *executable;
	int i;

	path = search(hash, "PATH");
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	executable = NULL;
	i = 0;
	while (dirs[i])
	{
		executable = ft_strjoin(dirs[i], "/");
		executable = ft_strjoin(executable, command);
		if (access(executable, X_OK) == 0)
			break ;
		free(executable);
		executable = NULL;
		i++;
	}
	ft_free_matrix((void **)dirs);
	return (executable);
}

pid_t execute_command(char **args, t_hash *hash)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(find_executable(args[0], hash), args, NULL) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minishell");

	return (pid);
}

void wait_for_command(pid_t pid)
{
	int status;

	waitpid(pid, &status, WUNTRACED);
}

pid_t execute_pipeline_command(char **args, t_hash *hash, int input_fd, int output_fd)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
		execute_command(args, hash);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minishell");
	return (pid);
}

void execute_pipeline(char **args1, char **args2, t_hash *hash)
{
	int pipefd[2];
	pid_t pid1;
	pid_t pid2;

	if (pipe(pipefd) == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}

	pid1 = execute_pipeline_command(args1, hash, STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	pid2 = execute_pipeline_command(args2, hash, pipefd[0], STDOUT_FILENO);
	close(pipefd[0]);

	wait_for_command(pid1);
	wait_for_command(pid2);
}

void	execute_line(char *line, t_hash *hash)
{
	int		i;
	char	**pipelines;
	char	**commands;

	pipelines = ft_split(line, '|');
	i = 0;
	while (pipelines[i])
	{
		commands = ft_split(pipelines[i], -7);
		if (pipelines[i + 1])
			execute_pipeline(commands, ft_split(pipelines[i + 1], -7), hash);
		else
			execute_command(commands, hash);
		ft_free_matrix((void**)commands);
		i++;
	}
	ft_free_matrix((void**)pipelines);
}