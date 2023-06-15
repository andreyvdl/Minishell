#include "../../includes/minishell.h"

void	free_son(void)
{
	size_t	looper;

	looper = 0;
	ft_free_matrix((void **)g_shell.envp);
	free_hash(g_shell.hash);
	ft_putstr_fd(*g_shell.command[g_shell.id].argv, 2); // test
	ft_putstr_fd("AAAAAAAAA\n", 2); // test
	while (looper < g_shell.nbr_sons)
	{
		ft_free_matrix((void **)g_shell.command[looper].argv);
		if (g_shell.command[looper].wr_here > STDOUT_FILENO)
			close(g_shell.command[looper].wr_here);
		if (g_shell.command[looper].rd_here > STDIN_FILENO)
			close(g_shell.command[looper].rd_here);
		looper++;
	}
	free(g_shell.command);
	rl_clear_history();
}

void	close_std_error(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	close_std(void)
{
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
