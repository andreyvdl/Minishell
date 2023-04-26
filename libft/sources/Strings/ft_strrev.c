/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:46:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 10:52:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*reverse_it(char *string, size_t end);
static size_t	get_string_size(char *string);

/**
 * @brief Reverses a string;
 * 
 * @param str A pointer to the string to be reversed;
 * @return The reversed string (char *); Or NULL if the received string is NULL;
 */
char	*ft_strrev(char *str)
{
	size_t	end;

	if (str == NULL)
		return (NULL);
	end = get_string_size(str) - 1;
	return (reverse_it(str, end));
}

static size_t	get_string_size(char *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static char	*reverse_it(char *string, size_t end)
{
	size_t	index;
	char	temporary;

	index = 0;
	while (index < end)
	{
		temporary = string[index];
		string[index] = string[end];
		string[end] = temporary;
		index++;
		end--;
	}
	return (string);
}
