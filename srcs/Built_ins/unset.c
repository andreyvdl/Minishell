#include "../../includes/minishell.h"

/* void	unset(char *str, t_hash *hash)
{
	while (*str && (*str != ' ' &&  *str != '\t'))
		str++;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	ft_putstr(str);
	ft_putchar('\n');
	(void)hash;
} */

static int	fake_remove(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (FALSE);
	while (ft_isalnum(*arg) || *arg == '_')
		arg++;
	if (*arg != '\0')
		return (FALSE);
	return (TRUE);
}

static void	remove_these(char **argv)
{
	int	printed;

	argv++;
	printed = 0;
	while (*argv != NULL)
	{
		if (fake_remove(*argv) == FALSE)
			printed = ft_printf_fd(STDERR_FILENO, ERR_UNSET_INVALID, *argv);
		argv++;
	}
	if (printed != 0)
	{
		free_son();
		exit(EXIT_FAILURE);
	}
}

void	ft_unset(char **argv)
{
	if (*(argv + 1) != NULL)
		remove_these(argv);
	free_son();
	exit(EXIT_SUCCESS);
}
