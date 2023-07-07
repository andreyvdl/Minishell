/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:03:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:03:57 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	dollar_case_count(char **str, size_t *size)
{
	size_t	len;
	char	*key;

	(*str)++;
	if (ft_isalpha(**str) == TRUE || **str == '_' || **str == '?')
	{
		if (**str == '?')
		{
			(*str)++;
			*size += ft_strlen(search(g_shell.hash, STATUS_CODE));
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		*size += ft_strlen(search(g_shell.hash, key));
		free(key);
	}
	else if (ft_isdigit(**str) == FALSE)
		(*size)++;
	while (ft_isalnum(**str) == TRUE || **str == '_')
		(*str)++;
}

static void	quote_case_count(char **str, size_t *size, char quote)
{
	(*str)++;
	while (**str != quote)
	{
		if (quote == '\'' && **str == '$')
		{
			**str = -1;
			(*str)++;
			(*size)++;
		}
		else if (quote == '\"' && **str == '$')
			dollar_case_count(str, size);
		else
		{
			(*str)++;
			(*size)++;
		}
	}
	(*str)++;
}

size_t	expand_size(char *str)
{
	size_t	size;

	size = 0;
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '\"')
			quote_case_count(&str, &size, *str);
		else if (*str == '$')
			dollar_case_count(&str, &size);
		else
		{
			str++;
			size++;
		}
	}
	return (size);
}
