#include "../../includes/minishell.h"

static int	env_is_directory(char **argv)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(*(argv + 1), &file_stat) == -1)
	{
		perror(ERR_STAT);
		insert_node(g_shell.hash, STATUS_CODE, "WORKAROUND");
		return (TRUE);
	}
	if (S_ISDIR(file_stat.st_mode))
		return (TRUE);
	return (FALSE);
}

static void	print_vars_env(void)
{
	t_node	*node;
	size_t	looper;

	looper = 0;
	while (looper < HASH_SIZE)
	{
		node = g_shell.hash->list[looper];
		while (node != NULL)
		{
			if (*node->key != '?' && node->value != NULL)
				ft_printf_ln("%s=%s", node->key, node->value);
			node = node->next;
		}
		looper++;
	}
	insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}

void	father_env(char **argv)
{
	if (*(argv + 1) != NULL && env_is_directory(argv) == TRUE)
	{
		if (ft_strcmp("WORKAROUND", search(g_shell.hash, STATUS_CODE)) != 0)
		{
			ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
			insert_node(g_shell.hash, STATUS_CODE, FATHER_EXEC_WENT_WRONG);
			return ;
		}
		insert_node(g_shell.hash, STATUS_CODE, FATHER_CMD_NOT_FOUND);
		return ;
	}
	else if (*(argv + 1) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_CMD_NOT_FOUND);
		return ;
	}
	print_vars_env();
}
