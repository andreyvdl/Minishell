#include "../../includes/minishell.h"

static int	echo_has_flag(char *flag)
{
	if (flag == NULL)
		return (FALSE);
	if (*flag != '-')
		return (FALSE);
	flag++;
	while (*flag == 'n' && *flag != '\0')
		flag++;
	if (*flag != '\0')
		return (FALSE);
	return (TRUE);
}

static void	print_it(char **argv, int newline)
{
	while (*argv != NULL)
	{
		ft_putstr(*argv);
		if (*(argv + 1) != NULL)
			ft_putchar(' ');
		argv++;
	}
	if (newline == TRUE)
		ft_putchar('\n');
}

void	ft_echo(char **argv)
{
	if (echo_has_flag(*(argv + 1)) == TRUE)
		print_it(argv + 2, FALSE);
	else
		print_it(argv + 1, TRUE);
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}
