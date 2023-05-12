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
	int	i;

	i = 0;
	ft_printf("%s", str);
	while (str && *str && str[i])
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				redirect_output_append(str);
			else
				redirect_output_trunc(str);
		}
		i++;
	}
	ft_printf("%s\n", str);
	return (1);
}