#include "../../includes/minishell.h"

int	unclosed_quotes_case(char **pipeline, char quote)
{
	(*pipeline)++;
	while (**pipeline != quote && **pipeline)
		(*pipeline)++;
	if (**pipeline == '\0')
	{
		ft_printf_fd(2, "\e[31mms: close this quote `%c`\e[0m\n", quote);
		return (true);
	}
	(*pipeline)++;
	return (false);
}

int	pipe_case(char **splited_pline)
{
	if (*(*splited_pline + 1) == '|' || *(*splited_pline + 1) == '&')
	{
		ft_printf_fd(2, "\e[31mms: unsuported syntax `%s`\e[0m\n", \
		*splited_pline);
		return (true);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd("\e[31mms: syntax error `EOL`\e[0m", 2);
		return (true);
	}
	else if (ft_ismetachar(**(splited_pline + 1)) && \
	**(splited_pline + 1) != '<' && **(splited_pline +1) != '>')
	{
		ft_printf_fd(2, "\e[31mms: syntax error after `%s`\e[0m\n", \
		*splited_pline);
		return (true);
	}
	return (false);
}

int	read_from_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, "<<<", 3) == 0 || ft_strstr(*splited_pline, \
	">") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(2, "\e[31mms: syntax error `%s`\e[0m\n", *splited_pline);
		return (true);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd("\e[31mms: syntax error `EOL`\e[0m", 2);
		return (true);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(2, "\e[31mms: syntax error after `%s`\e[0m\n", \
		*splited_pline);
		return (true);
	}
	return (false);
}

int	write_to_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, ">>>", 3) == 0 || ft_strstr(*splited_pline, \
	"<") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(2, "\e[31mms: syntax error `%s`\e[0m\n", *splited_pline);
		return (true);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd("\e[31mms: syntax error `EOL`\e[0m", 2);
		return (true);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(2, "\e[31mms: syntax error after `%s`\e[0m\n", \
		*splited_pline);
		return (true);
	}
	return (false);
}
