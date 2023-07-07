/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_spacer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:13:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:13:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	inside_quote_counter(char **str, size_t *counter, char quote)
{
	(*counter)++;
	(*str)++;
	while (**str && **str != quote)
	{
		(*counter)++;
		(*str)++;
	}
	if (**str == quote && ft_ismetachar(*(*str + 1)))
		(*counter)++;
	(*counter)++;
}

void	inside_quote_copy(char **str, char **new, char quote)
{
	**new = **str;
	(*new)++;
	(*str)++;
	while (**str && **str != quote)
	{
		**new = **str;
		(*new)++;
		(*str)++;
	}
	**new = **str;
	(*new)++;
	if (**str == quote && ft_ismetachar(*(*str + 1)))
	{
		**new = ' ';
		(*new)++;
	}
	if (**str)
		(*str)++;
}
