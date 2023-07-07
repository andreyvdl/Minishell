/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_expand_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:01:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/07 13:04:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	aux_copy(char **new, char *value)
{
	size_t	index;

	if (value == NULL)
		return ;
	index = 0;
	while (value[index] != '\0')
	{
		**new = value[index];
		(*new)++;
		index++;
	}
}

static void	expand_value_copy(char **new, char **str)
{
	size_t	len;
	char	*key;

	(*str)++;
	if (ft_isalpha(**str) == TRUE || **str == '_' || **str == '?')
	{
		if (**str == '?')
		{
			(*str)++;
			aux_copy(new, search(g_shell.hash, STATUS_CODE));
			return ;
		}
		len = 0;
		while (ft_isalnum(*(*str + len)) == TRUE || *(*str + len) == '_')
			len++;
		key = ft_substr(*str, 0, len);
		aux_copy(new, search(g_shell.hash, key));
		free(key);
	}
	else if (ft_isdigit(**str) == FALSE)
		aux_copy(new, "$");
	while (ft_isalnum(**str) == TRUE || **str == '_')
		(*str)++;
}

static void	skip_first_quote(char **new, char **str, char quote)
{
	(*str)++;
	while (**str != '\0' && **str != quote)
	{
		if (**str == '$')
			expand_value_copy(new, str);
		else if (**str == -1)
		{
			**new = '$';
			(*str)++;
			(*new)++;
		}
		else
		{
			**new = **str;
			(*str)++;
			(*new)++;
		}
	}
	(*str)++;
}

void	expand_copy(char *new, char *str)
{
	while (*str != '\0')
	{
		if (*str == '\"' || *str == '\'')
			skip_first_quote(&new, &str, *str);
		else if (*str == -1)
		{
			*new = '$';
			str++;
			new++;
		}
		else if (*str == '$')
			expand_value_copy(&new, &str);
		else
		{
			*new = *str;
			str++;
			new++;
		}
	}
}
