#include "../../includes/minishell.h"

int	redirect_output_append(char *filename, t_command *son)
{
	char	*temp;
	int		file_des;

	temp = remove_quotes_and_expand(filename);
	file_des = open(filename, O_WRONLY | O_CREAT | O_APPEND, PERM_CREATE);
	if (temp != filename)
		free(temp);
	if (file_des == -1)
	{
		if (son->wr_here != -1)
			close(son->wr_here);
		son->wr_here = file_des;
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	if (son->wr_here != -1)
		close(son->wr_here);
	son->wr_here = file_des;
	return (REDI_OK);
}
