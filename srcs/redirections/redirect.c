#include "../../includes/minishell.h"

int redirect_output_trunc(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}


int redirect_output_append(char *filename)
{
	int fd;


	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1);


	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}

int redirect_input(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}

int redirect_input_string(char *str)
{
	int pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);

	if (write(pipefd[1], str, ft_strlen(str)) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		close(pipefd[0]);
		return (-1);
	}
	close(pipefd[0]);
	return (0);
}

int		redirection(char *str)
{
	int		i;
	int		original_stdout;
	char	**tokens;

	original_stdout = dup(STDOUT_FILENO);
	i = 0;
	tokens = ft_split(str, -7);

	while (tokens && *tokens && **tokens && tokens[i])
	{
		if (ft_strcmp(tokens[i], ">") == 0)
		{
			if (tokens[i + 1])
				redirect_output_trunc(tokens[i + 1]);
		}
		else if (ft_strcmp(tokens[i], ">>") == 0)
		{
			if (tokens[i + 1])
				redirect_output_append(tokens[i + 1]);
		}
		i++;
	}
	i = 1;
	while (tokens && *tokens && **tokens && tokens[i])
		printf("%s\n", tokens[i++]);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (1);
}