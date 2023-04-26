/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:21:59 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 15:33:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	go_to_string_end(const char *s);

/**
 * @brief Locates the last occurrence of c in the string s;
 * 
 * @param s A pointer to the string to be scanned;
 * @param c The character to be located;
 * @return return a pointer to the located character (char *); Or NULL if the
 * 			character does not appear in the string;
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = go_to_string_end(s);
	while (index > 0)
	{
		if (s[index] == c)
			return (&((char *)s)[index]);
		index--;
	}
	if (s[index] == c)
		return ((char *)s);
	return (NULL);
}

static size_t	go_to_string_end(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
