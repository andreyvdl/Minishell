#include "../../includes/minishell.h"

int	unclosed_quotes_case(char **pipeline, char quote)
{
	(*pipeline)++;
	while (**pipeline != quote && **pipeline)
		(*pipeline)++;
	if (**pipeline == '\0')
	{
		ft_printf_fd(STDERR_FILENO, RED"ms: close this quote `%c`\n"RST, \
		quote);
		return (TRUE);
	}
	(*pipeline)++;
	return (FALSE);
}

int	pipe_case(char **splited_pline)
{
	if (*(*splited_pline + 1) == '|' || *(*splited_pline + 1) == '&')
	{
		ft_printf_fd(STDERR_FILENO, RED"ms: unsuported syntax `%s`\n"RST, \
		*splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(RED"ms: syntax error `EOL`"RST, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)) && \
	**(splited_pline + 1) != '<' && **(splited_pline +1) != '>')
	{
		ft_printf_fd(STDERR_FILENO, \
		RED"ms: syntax error after `%s`\n"RST, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}

int	read_from_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, "<<<", 3) == 0 || ft_strstr(*splited_pline, \
	">") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(STDERR_FILENO, \
		RED"ms: syntax error `%s`\n"RST, *splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(RED"ms: syntax error `EOL`"RST, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(STDERR_FILENO, \
		RED"ms: syntax error after `%s`\n"RST, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}

int	write_to_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, ">>>", 3) == 0 || ft_strstr(*splited_pline, \
	"<") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(STDERR_FILENO, \
		RED"ms: syntax error `%s`\n"RST, *splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(RED"ms: syntax error `EOL`"RST, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(STDERR_FILENO, \
		RED"ms: syntax error after `%s`\n"RST, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}
