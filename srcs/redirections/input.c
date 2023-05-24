#include "../../includes/minishell.h"

static int	open_filename(char *filename, t_command *son)
{
	
	son->rd_here = open(filename, O_RDONLY);
}

int	redirect_input(char *filename, t_command *son)
{
	char	*temp;

	temp = remove_quotes_and_expand(filename);
	if (temp == filename)
	{
		if (open_filename(filename, son) == -1)
		{
			perror(ERR_READING);
			return (REDI_ERR);
		}
	}
	else
	{
		open_temp(temp, son);
		son->rd_here = open(temp, O_RDONLY);
		free(temp);
		if (son->rd_here == -1)
		{
			perror(ERR_READING);
			return (REDI_ERR);
		}
	}
	return (REDI_OK);
}
