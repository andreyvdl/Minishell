#include "../../includes/minishell.h"

void	free_all_and_exit(t_hash *hash)
{
	ft_putstr("exit\n");
	free_hash(hash);
	rl_clear_history();
	exit(0);
}
