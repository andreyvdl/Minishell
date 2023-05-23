#include "../../includes/minishell.h"

int	redirect_output_trunc(char *filename, t_command *son)
{
	char	*temp;

	temp = remove_quotes_and_expand(filename);
	son->wr_here = open(temp, O_WRONLY | O_CREAT | O_TRUNC, PERM_CREATE);
	free(temp);
	if (son->wr_here == -1)
	{
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	// if (dup2(son->wr_here, STDOUT_FILENO) == -1)
	// {
	// 	close(son->wr_here);
	// 	perror(ERR_WRITING);
	// 	return (REDI_ERR);
	// }
	// close(son->wr_here);
	// son->wr_here = STDOUT_FILENO;
	return (REDI_OK);
}
