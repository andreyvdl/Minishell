#include "../../includes/minishell.h"

int redirect_output_trunc(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, PERM_CREATE);
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


int	redirect_output_append(char *filename, t_command *son, t_hash *hash)
{
	if (access(filename, W_OK) == -1)
	{
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	son->wr_here = open(filename, O_WRONLY | O_CREAT | O_APPEND, PERM_CREATE);
	if (son->wr_here == -1)
	{
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	if (dup2(son->wr_here, STDOUT_FILENO) == -1)
	{
		perror(ERR_WRITING);
		close(son->wr_here);
		return (REDI_ERR);
	}
	close(son->wr_here);
	return (REDI_OK);
}

int	redirect_input(char *filename, t_command *son, t_hash *hash)
{
	son->rd_here = open(filename, O_RDONLY);
	if (son->rd_here == -1)
	{
		perror(ERR_READING);
		return (REDI_ERR);
	}
	if (dup2(son->rd_here, STDIN_FILENO) == -1)
	{
		perror(ERR_READING);
		close(son->rd_here);
		return (ERR_READING);
	}
	close(son->rd_here);
	return (REDI_OK);
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

int	redirection(char **str, t_hash *hash, t_command *son)
{
	int		original_stdout;

	original_stdout = dup(STDOUT_FILENO);
	while (*str)
	{
		if (ft_strcmp(str, ">>") == 0)
			redirect_output_append(str + 1, son, hash);
		else if (ft_strcmp(str, "<<") == 0)
			if (heredoc(hash, str + 1, son))
				return (REDI_SIGNAL);
		else if (ft_strcmp(str, "<") == 0)
			redirect_input(str + 1, son, hash);
		else if (ft_strcmp(str, ">") == 0)
			redirect_output_trunc(str + 1, son, hash);
		str++;
	}
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (REDI_OK);
}
