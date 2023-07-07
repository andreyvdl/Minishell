/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:05:57 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:05:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unclosed_quotes_case(char **pipeline, char quote)
{
	(*pipeline)++;
	while (**pipeline != quote && **pipeline)
		(*pipeline)++;
	if (**pipeline == '\0')
	{
		ft_printf_fd(STDERR_FILENO, ERR_QUOTE, quote);
		return (TRUE);
	}
	(*pipeline)++;
	return (FALSE);
}

int	pipe_case(char **splited_pline)
{
	if (*(*splited_pline + 1) == '|' || *(*splited_pline + 1) == '&')
	{
		ft_printf_fd(STDERR_FILENO, ERR_UNS_SYNTAX, *splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(ERR_EOL_SYNTAX, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)) && \
	**(splited_pline + 1) != '<' && **(splited_pline +1) != '>')
	{
		ft_printf_fd(STDERR_FILENO, ERR_NEXT_SYNTAX, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}

int	read_from_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, "<<<", 3) == 0 || ft_strstr(*splited_pline, \
	">") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(STDERR_FILENO, ERR_NOW_SYNTAX, *splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(ERR_EOL_SYNTAX, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(STDERR_FILENO, ERR_NEXT_SYNTAX, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}

int	write_to_case(char **splited_pline)
{
	if (ft_strncmp(*splited_pline, ">>>", 3) == 0 || ft_strstr(*splited_pline, \
	"<") || ft_strstr(*splited_pline, "&"))
	{
		ft_printf_fd(STDERR_FILENO, ERR_NOW_SYNTAX, *splited_pline);
		return (TRUE);
	}
	else if (*(splited_pline + 1) == NULL)
	{
		ft_putendl_fd(ERR_EOL_SYNTAX, STDERR_FILENO);
		return (TRUE);
	}
	else if (ft_ismetachar(**(splited_pline + 1)))
	{
		ft_printf_fd(STDERR_FILENO, ERR_NEXT_SYNTAX, *splited_pline);
		return (TRUE);
	}
	return (FALSE);
}
