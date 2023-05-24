#include "../../includes/minishell.h"

// int redirect_input_string(char *str)
// {
// 	int pipefd[2];

// 	if (pipe(pipefd) == -1)
// 		return (-1);

// 	if (write(pipefd[1], str, ft_strlen(str)) == -1)
// 	{
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		return (-1);
// 	}
// 	close(pipefd[1]);

// 	if (dup2(pipefd[0], STDIN_FILENO) == -1)
// 	{
// 		close(pipefd[0]);
// 		return (-1);
// 	}
// 	close(pipefd[0]);
// 	return (0);
// }

static void	close_opened()

static int	writers(char **str, t_command *son)
{
	if (ft_strcmp(*str, ">>") == 0)
	{
		if (redirect_output_append(str + 1, son) == REDI_ERR)
			return (REDI_ERR);
	}
	else
		if (redirect_output_trunc(str + 1, son) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

static int	readers(char **str, t_command *son)
{
	if (ft_strcmp(*str, "<<") == 0)
	{
		if (heredoc(str + 1, son) == REDI_SIGNAL)
			return (REDI_SIGNAL);
	}
	else
		if (redirect_input(str + 1, son) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

int	redirection(char **str, t_command *son)
{
	int	status;
	int	original_stdout;

	status = REDI_OK;
	original_stdout = dup(STDOUT_FILENO);
	g_shell.REDIRECT_REST = str;
	while (*str)
	{
		if (**str == '<')
		{
			status = readers(str, son);
			if (status != REDI_OK)
				break ;
		}
		else if (**str == '>')
		{
			status = writers(str, son);
			if (status != REDI_OK)
				break ;
		}
		str += 2;
	}
	close_opened(son);
	return (status);
}
