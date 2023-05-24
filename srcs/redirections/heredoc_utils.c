#include "../../includes/minishell.h"

void	no_expansion_loop(char *limiter, t_command *son)
{
	char	*line;

	while (TRUE)
	{
		line = readline(HEREDOC_PROMPT);
		if (line == NULL)
		{
			ft_printf_fd(STDOUT_FILENO, WAR_HEREDOC, limiter);
			break ;
		}
		else if (ft_strcmp(line, limiter) == 0)
			break ;
		ft_putendl_fd(line, son->rd_here);
	}
}
