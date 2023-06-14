/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:51:30 by adantas-          #+#    #+#             */
/*   Updated: 2023/05/08 15:12:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		set_in_beginning(char character, char const *set);
static int		set_in_ending(char character, char const *set);
static char		*copy_trimmed(char const *string, size_t start, size_t end);
static size_t	get_string_size(char const *string);

/**
 * @brief Removes the character of set in s1, creating a new string in the
 * 			process;
 * 
 * @param s1 A pointer to the string to be trimmed;
 * @param set A pointer to the characters that delimit the string;
 * @return A pointer to the new trimmed string (char *); NULL if allocation
 * 			fails or if s1 is NULL;
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL && *s1 == '\0')
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && set_in_beginning(s1[start], set) == TRUE)
		start++;
	end = get_string_size(s1) - 1;
	while (end > start && set_in_ending(s1[end], set) == TRUE)
		end--;
	return (copy_trimmed(s1, start, end + 1));
}

static int	set_in_beginning(char character, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == character)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

static size_t	get_string_size(char const *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static int	set_in_ending(char character, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == character)
			return (TRUE);
		index++;
	}
	return (FALSE);
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
