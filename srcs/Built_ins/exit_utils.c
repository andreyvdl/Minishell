#include "../../includes/minishell.h"

static int	check_positive_long(char *nbr)
{
	size_t	walker;

	walker = 0;
	while (ft_isdigit(nbr[walker]))
		walker++;
	if (walker > EXIT_LONG_SIZE)
		return (FALSE);
	else if (walker == EXIT_LONG_SIZE)
	{
		walker = 0;
		while (EXIT_LONG_POS[walker] != '\0')
		{
			if (*nbr++ > EXIT_LONG_POS[walker++])
				return (FALSE);
		}
	}
	return (TRUE);
}

static int	check_negative_long(char *nbr)
{
	size_t	walker;

	walker = 0;
	while (ft_isdigit(nbr[walker]))
		walker++;
	if (walker > EXIT_LONG_SIZE)
		return (FALSE);
	else if (walker == EXIT_LONG_SIZE)
	{
		walker = 0;
		while (EXIT_LONG_NEG[walker] != '\0')
		{
			if (*nbr++ > EXIT_LONG_NEG[walker++])
				return (FALSE);
		}
	}
	return (TRUE);
}

int	number_big(char *arg)
{
	while ((*arg == '\t' || *arg == ' ') && *arg != '\0')
		arg++;
	if (*arg == '-')
	{
		if (check_negative_long(arg + 1) == FALSE)
			return (TRUE);
	}
	else if (*arg == '+')
	{
		if (check_positive_long(arg + 1) == FALSE)
			return (TRUE);
	}
	else if (ft_isdigit(*arg))
	{
		if (check_positive_long(arg) == FALSE)
			return (TRUE);
	}
	return (FALSE);
}
