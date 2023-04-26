/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:40:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 11:11:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Locates the first occurrence of c in the string pointed to by s;
 * 
 * @param s A pointer to the string to be scanned;
 * @param c The character to be located;
 * @return return a pointer to the located character (char *); Or NULL if the
 * 			character does not appear in the string or if s points to NULL;
 */
char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (&((char *)s)[index]);
		index++;
	}
	if (s[index] == c)
		return (&((char *)s)[index]);
	return (NULL);
}
