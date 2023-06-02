#include "../../includes/minishell.h"

int	redirect_output_trunc(char *filename, t_command *son, size_t id)
{
	char	*temp;
	int		file_des;

	temp = remove_quote_or_expand(filename);
	file_des = open(temp, TRUNC, PERM_CREATE);
	if (temp != filename)
		free(temp);
	if (file_des == -1)
	{
		if (son[id].wr_here > STDOUT_FILENO)
			close(son[id].wr_here);
		son[id].wr_here = -42;
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	if (son[id].wr_here > STDOUT_FILENO)
		close(son[id].wr_here);
	son[id].wr_here = file_des;
	return (REDI_OK);
}
