/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_easy_splitter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:13:22 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:13:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ignore_it(char **str, char quote)
{
	(*str)++;
	while (**str != quote && **str)
		(*str)++;
	if (**str)
		(*str)++;
}

void	easy_splitter(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
		{
			*str = -7;
			str++;
		}
		else if (*str == '\'' || *str == '\"')
			ignore_it(&str, *str);
		else
			str++;
	}
}
