#include "../../includes/minishell.h"

int	redirect_input(char *filename, t_command *son)
{
	char	*temp;

	temp = remove_quotes_and_expand();
	if (access(temp, R_OK) == -1)
	{
		free(temp);
		perror(ERR_READING);
		return (REDI_ERR);
	}
	son->rd_here = open(temp, O_RDONLY);
	free(temp);
	if (son->rd_here == -1)
	{
		perror(ERR_READING);
		return (REDI_ERR);
	}
	// if (dup2(son->rd_here, STDIN_FILENO) == -1)
	// {
	// 	perror(ERR_READING);
	// 	close(son->rd_here);
	// 	return (ERR_READING);
	// }
	// close(son->rd_here);
	return (REDI_OK);
}
