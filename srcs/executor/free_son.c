#include "../../includes/minishell.h"

static void	free_son_hash(t_hash *hash)
{
	size_t	looper;
	t_node	*node;

	looper = 0;
	while (looper < HASH_SIZE)
	{
		node = hash->list[looper];
		if (node != NULL)
		{
			free(node->key);
			free(node->value);
			free(node);
		}
		looper++;
	}
}

void	free_son(void)
{
	size_t	looper;

	looper = 0;
	while (looper < g_shell.nbr_sons)
	{
		ft_free_matrix((void **)g_shell.command[looper].argv);
		if (g_shell.command[looper].wr_here > STDOUT_FILENO)
			close(g_shell.command[looper].wr_here);
		if (g_shell.command[looper].rd_here > STDIN_FILENO)
			close(g_shell.command[looper].rd_here);
		looper++;
	}
	ft_free_matrix((void **)g_shell.envp);
	free(g_shell.command);
	free_son_hash(g_shell.hash);
}
