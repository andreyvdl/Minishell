/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:04:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:04:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	solo_value_size(char **str, size_t *size)
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

size_t	solo_size(char *str)
{
	size_t	size;

	size = 0;
	while (*str != '\0')
	{
		if (*str == '$')
			solo_value_size(&str, &size);
		else
		{
			str++;
			size++;
		}
	}
	return (size);
}

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

static void	solo_value_copy(char **new, char **str)
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
	else if (ft_isdigit(**str) == FALSE && (**str) != 0 && (*str)++)
		aux_copy(new, "$");
	while (ft_isalnum(**str) == TRUE || **str == '_')
		(*str)++;
}

void	solo_copy(char *new, char *str)
{
	while (*str != '\0')
	{
		if (*str == '$')
			solo_value_copy(&new, &str);
		else
		{
			*new = *str;
			new++;
			str++;
		}
	}
}
