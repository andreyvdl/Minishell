#include "../../includes/minishell.h"


int	isbuiltin(char *check)
{
	int		get;
	int		i;
	char	**builtin;
	
	builtin = ft_split(BUILTIN, ' ');
	i = 0;
	get = 0;
	while (builtin && builtin[i])
	{
		if (ft_strcmp(builtin[i], check) == 0)
		{
			get = 1;
			break;
		}
		i++;
	}
	ft_free_matrix((void **)builtin);
	return (get);	
}
/* 
TODO: função que vê se o coamndo é builtin e volta bool
int	isbuiltin()
 */
