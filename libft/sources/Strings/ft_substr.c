/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:02:58 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 00:13:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*fill_sub_string(char const *string, char *sub_string, \
								unsigned int start, size_t len);
static char		*mini_sub_string(void);
static size_t	get_string_size(char const *s);

/**
 * @brief Creates a substring of a string;
 * 
 * @param s A pointer to the main string;
 * @param start The index of the begin of the substring in the string;
 * @param len The size of the substring;
 * @return If the size of the string is less than the start it returns a empty
 * 			string; If the string size if less than the len it returns the
 * 			full string; If the string size is equal to len it returns the
 * 			difference between the string size and the start point; If none of
 * 			the previous conditions are truth than it copies the len of the
 * 			string from the start point; If allocation fails it returns NULL;
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	string_size;

	if (s == NULL)
		return (NULL);
	string_size = get_string_size(s);
	if (string_size < start)
		return (mini_sub_string());
	else if (string_size < len)
		sub_string = (char *)malloc(string_size + 1);
	else if (string_size == len)
		sub_string = (char *)malloc(string_size - start + 1);
	else
		sub_string = (char *)malloc(len + 1);
	if (sub_string == NULL)
		return (NULL);
	return (fill_sub_string(s, sub_string, start, len));
}

static size_t	get_string_size(char const *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

static char	*mini_sub_string(void)
{
	char	*sub_string;

	sub_string = (char *)malloc(sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	sub_string[0] = '\0';
	return (sub_string);
}

static char	*fill_sub_string(char const *string, char *sub_string, \
							unsigned int start, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && string[start] != '\0')
	{
		sub_string[index] = string[start];
		index++;
		start++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}
