#include "../../includes/minishell.h"

int	set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash)
{
	int		status;

	status = REDI_OK;
	g_shell.command = (t_command *)ft_calloc(nbr_cmds + 1, sizeof(t_command));
	g_shell.id = 0;
	g_shell.nbr_sons = nbr_cmds;
	g_shell.pipeline_rest = cmds;
	while (g_shell.id < nbr_cmds)
	{
		status = fill_son_orders(g_shell.command, *cmds);
		if (status == REDI_SIGNAL)
			return (status);
		g_shell.id++;
		cmds++;
	}
	g_shell.id = 0;
	g_shell.envp = hash_to_matrix(hash);
	return (status);
}
