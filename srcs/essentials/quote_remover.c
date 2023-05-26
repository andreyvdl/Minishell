#include "../../includes/minishell.h"

void	quote_remover(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\'')
		{
			ft_memmove(str, str + 1, ft_strlen(str + 1));
			while (*str != '\'')
			{
				if (*str == '$')
					*str = -1;
					str++;
			}
			ft_memmove(str, str + 1, ft_strlen(str + 1));
		}
		else if (*str == '\"')
		{
			ft_memmove(str, str + 1, ft_strlen(str + 1));
			while (*str != '\"')
				str++;
			ft_memmove(str, str + 1, ft_strlen(str + 1));
		}
		else
			str++;
	}
}
