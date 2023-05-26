#include "../../includes/minishell.h"

static void	close_opened()

static int	writers(char **str, t_command *son, size_t id)
{
	if (ft_strcmp(*str, ">>") == 0)
	{
		if (redirect_output_append(str + 1, son, id) == REDI_ERR)
			return (REDI_ERR);
	}
	else
		if (redirect_output_trunc(str + 1, son, id) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

static int	readers(char **str, t_command *son, size_t id)
{
	if (ft_strcmp(*str, "<<") == 0)
	{
		if (heredoc(str + 1, son, id) != REDI_SIGNAL)
			return (REDI_SIGNAL);
	}
	else
		if (redirect_input(str + 1, son, id) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

int	redirection(char **str, t_command *son, size_t id)
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
			status = readers(str, son, id);
			if (status != REDI_OK)
				break ;
		}
		else if (**str == '>')
		{
			status = writers(str, son, id);
			if (status != REDI_OK)
				break ;
		}
		str += 2;
	}
	if (*str != NULL)
		close_opened(son, id);
	return (status);
}
