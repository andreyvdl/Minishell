/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:02:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/05/11 11:06:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*copy_trimmed(char const *string, size_t start, size_t end);
static size_t	get_string_size(char const *string);

char	*ft_chrtrim(char const *s1, char const set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL && *s1 == '\0')
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && s1[start] == set)
		start++;
	end = get_string_size(s1) - 1;
	while (end > start && s1[end] == set)
		end--;
	return (copy_trimmed(s1, start, end + 1));
}

static size_t	get_string_size(char const *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static char	*copy_trimmed(char const *string, size_t start, size_t end)
{
	char	*trimmed;
	size_t	index;

	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	index = 0;
	while (start < end)
	{
		trimmed[index] = string[start];
		start++;
		index++;
	}
	trimmed[index] = '\0';
	return (trimmed);
}
