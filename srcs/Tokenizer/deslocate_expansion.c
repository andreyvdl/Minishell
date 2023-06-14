#include "../../includes/minishell.h"

static void	copy_next_arg(char **argv, char **arg_ahead)
{
	if (*arg_ahead == NULL)
	{
		free(*argv);
		*argv = NULL;
		return ;
	}
	while (*arg_ahead)
	{
		if (**arg_ahead != '\0')
		{
			free(*argv);
			*argv = ft_strdup(*arg_ahead);
			free(*arg_ahead);
			*arg_ahead = (char *)ft_calloc(1, sizeof(char));
			return ;
		}
		arg_ahead++;
	}
	if (*arg_ahead == NULL)
	{
		free(*argv);
		*argv = NULL;
	}
}

static void	command_move(char **argv)
{
	if (**argv == '\0' && *(argv + 1) == NULL)
		return ;
	while (*argv)
	{
		if (**argv == '\0')
		{
			copy_next_arg(argv, argv + 1);
			continue ;
		}
		argv++;
	}
}

void	deslocate_expansion_empty(void)
{
	size_t	looper;

	looper = 0;
	while (looper < g_shell.nbr_sons)
	{
		if (g_shell.command[looper].argv && *g_shell.command[looper].argv)
			command_move(g_shell.command[looper].argv);
		looper++;
	}
}
