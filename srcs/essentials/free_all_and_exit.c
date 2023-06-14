#include "../../includes/minishell.h"

void	free_all_and_exit(t_hash *hash)
{
	ft_putstr("exit\n");
	free_hash(hash);
	rl_clear_history();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	if (access(HEREDOC_PATH, F_OK) != -1)
		unlink(HEREDOC_PATH);
	exit(0);
}
