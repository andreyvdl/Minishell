/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:26:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 11:54:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief scans the initial n bytes of the memory area pointed to by s for the
 * 			first instance of c;
 * 
 * @param s A pointer to the memory area to be scanned;
 * @param c The character to be located;
 * @param n The maximum number of bytes to be scanned;
 * @return A pointer to the matching byte or NULL if the character does not
 * 			occur in the given memory area or if s is NULL or if n is 0;
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*temporary;
	unsigned char	character;

	if (s == NULL || n == 0)
		return (NULL);
	temporary = (unsigned char *)s;
	character = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (temporary[index] == character)
			return (&((void *)s)[index]);
		index++;
	}
	return (NULL);
}
