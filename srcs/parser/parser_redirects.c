#include "../../includes/minishell.h"

int	redirect_invalid(char **split_pline, t_hash *hash)
{
	while (*split_pline)
	{
		if (ft_strchr(*split_pline, '<') && !ft_strstr(*split_pline, "<<"))
		{
			if (reading_invalid(*(split_pline + 1), hash))
				return (TRUE);
		}
		else if (ft_strchr(*split_pline, '>'))
		{
			if (writing_invalid(*(split_pline + 1), hash))
				return (TRUE);
		}
		split_pline++;
	}
	return (FALSE);
}
