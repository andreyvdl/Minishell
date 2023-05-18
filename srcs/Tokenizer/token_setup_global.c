#include "../../includes/minishell.h"

void	set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash)
{
	/* 
	 * later we think on how to give free to all of this;
	*/
	g_shell.envp = hash_to_matrix(hash);
	g_shell.argv = (char ***)ft_calloc(nbr_cmds + 1, sizeof(char **));
	g_shell.binp = (char **)ft_calloc(nbr_cmds + 1, sizeof(char *));
	fill_argv
}
