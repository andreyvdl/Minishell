#include "../../includes/minishell.h"

/* void	env()
{
	char	**env;
	int		i;

	i = 0;
	env = g_shell.envp;
	if (ft_matrixlen((const char **)g_shell.command->argv) > 1)
		return ((void)ft_printf("Command is: env!"));
	while (env && env[i])
		ft_printf("%s\n", env[i++]);
} */

static int	env_is_directory(char **argv)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(*(argv + 1), &file_stat) == -1)
	{
		free_son();
		perror(ERR_STAT);
		exit(EXIT_FAILURE);
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
	free_son();
	exit(EXIT_SUCCESS);
}

void	ft_env(char **argv)
{
	if (*(argv + 1) != NULL && env_is_directory(argv) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
		free_son();
		exit(EXEC_WENT_WRONG);
	}
	else if (*(argv + 1) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
		free_son();
		exit(CMD_NOT_FOUND);
	}
	print_vars_env();
}
