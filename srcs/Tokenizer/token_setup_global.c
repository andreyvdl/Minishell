#include "../../includes/minishell.h"

int	set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash)
{
	int		status;
	size_t	counter;

	g_shell.command = (t_command *)ft_calloc(nbr_cmds + 1, sizeof(t_command));
	counter = 0;
	g_shell.FREE_THIS_MOTHERFUCKER = cmds;
	while (counter < nbr_cmds)
	{
		status = fill_son_orders(g_shell.command[counter], *cmds, hash);
		counter++;
		cmds++;
	}
	g_shell.id = 0;
	g_shell.nbr_sons = nbr_cmds;
	g_shell.envp = hash_to_matrix(hash);
}
