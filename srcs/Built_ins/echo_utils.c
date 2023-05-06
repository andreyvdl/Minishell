#include "../../includes/minishell.h"

int	intersections(char *str, char inter)
{
	int	start;
	int	end;

	start = 0;
	while(str[start] && str[start] != inter)
		start++;
	end = start + 1;
	while(str[end] && str[end] != inter)
		end++;
	start += 1;
	while (start < end)
	{
		ft_putchar(str[start]);
		start++;
	}
	ft_putchar('\n');
	return (end);
}