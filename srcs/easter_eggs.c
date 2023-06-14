#include "../includes/minishell.h"

static void	ee_mgs(void)
{
	ft_putstr("did you really excpect some kind of easter egg?\n");
}

void	easter_eggs(char *flags)
{
	size_t	count_v;

	count_v = 0;
	while (*flags)
	{
		if (*flags == 'v')
			count_v++;
		flags++;
	}
	if (count_v != 0)
		ee_mgs();
}
