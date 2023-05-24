#include "../../includes/minishell.h"

static char	*expand_vars_heredoc(char *str, t_hash *hash)
{
	char	*expanded_str;
	size_t	size;

	if (ft_strchr(str, '$'))
	{
		size = size_with_values_heredoc(str, hash);
		expanded_str = (char *)ft_calloc((size + 1), sizeof(char));
		copy_with_expansions_heredoc(str, expanded_str, hash);
		return (expanded_str);
	}
	else
		return (str);
}

static char	*heredoc_expand(char *str)
{
	char	*new;

	new = expand_vars_heredoc(str, g_shell.hash);
	if (str == new)
		return (str);
	free(str);
	return (new);
}

void	expansion_loop(char *limiter, t_command *son)
{
	char	*line;

	while (TRUE)
	{
		line = redline(HEREDOC_PROMPT);
		if (line == NULL)
		{
			ft_printf_fd(STDOUT_FILENO, WAR_HEREDOC, limiter);
			break ;
		}
		else if (*line != '\0')
			line = heredoc_expand(line);
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, son->rd_here);
		free(line);
	}
}

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
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, son->rd_here);
		free(line);
	}
}

