#include "../../includes/minishell.h"

static void	closer(t_command *son, size_t id)
{
	size_t	temp_id;

	temp_id = id;
	while (temp_id <= id)
	{
		if (son[temp_id].rd_here > -1)
		{
			close(son[temp_id].rd_here);
			son[temp_id].rd_here = -130;
		}
		if (son[temp_id].wr_here > -1)
		{
			close(son[temp_id].wr_here);
			son[temp_id].wr_here = -130;
		}
		temp_id--;
	}
}

static void	close_opened(int status, t_command *son, size_t id)
{
	if (status == REDI_ERR)
	{
		if (son[id].rd_here > STDIN_FILENO)
		{
			close(son[id].rd_here);
			son[id].rd_here = REDIRECT_ERROR;
		}
		if (son[id].wr_here > STDOUT_FILENO)
		{
			close(son[id].wr_here);
			son[id].wr_here = REDIRECT_ERROR;
		}
		return ;
	}
	closer(son, id);
}

static int	writers(char **str, t_command *son, size_t id)
{
	if (ft_strcmp(*str, ">>") == 0)
	{
		if (redirect_output_append(*(str + 1), son, id) == REDI_ERR)
			return (REDI_ERR);
	}
	else
		if (redirect_output_trunc(*(str + 1), son, id) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

static int	readers(char **str, t_command *son, size_t id)
{
	if (ft_strcmp(*str, "<<") == 0)
	{
		if (heredoc(*(str + 1), son, id) == REDI_SIGNAL)
			return (REDI_SIGNAL);
		close(son[id].rd_here);
		son[id].rd_here = open(HEREDOC_PATH, O_RDONLY);
	}
	else
		if (redirect_input(*(str + 1), son, id) == REDI_ERR)
			return (REDI_ERR);
	return (REDI_OK);
}

int	redirection(char **str, t_command *son, size_t id)
{
	int	status;

	status = REDI_OK;
	g_shell.redirect_rest = str;
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
		close_opened(status, son, id);
	return (status);
}
