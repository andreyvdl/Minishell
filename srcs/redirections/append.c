#include "../../includes/minishell.h"

int	redirect_output_append(char *filename, t_command *son, size_t id)
{
	char	*temp;
	int		file_des;

	temp = remove_quotes_and_expand(filename);
	file_des = open(temp, APPEND, PERM_CREATE);
	if (temp != filename)
		free(temp);
	if (file_des == -1)
	{
		if (son[id].wr_here != -1)
			close(son[id].wr_here);
		son[id].wr_here = -1;
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	if (son[id].wr_here != -1)
		close(son[id].wr_here);
	son[id].wr_here = -1;
	return (REDI_OK);
}
