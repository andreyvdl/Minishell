/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:37:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 16:25:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string little in
 * 			the string big, where not more than len characters are scanned;
 * 
 * @param big A pointer to the string to be scanned;
 * @param little A pointer to the string to be found;
 * @param len The maximum number of characters to be scanned;
 * @return The pointer to the first occurrence of little in big (char *); Or
 * 			NULL if little does not appear in big; Or big if little is empty;
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_walker;
	size_t	index;

	if ((little[0] == '\0' && big[0] == '\0') || little[0] == '\0')
		return ((char *)big);
	big_walker = 0;
	while (big_walker < len && big[big_walker] != '\0')
	{
		index = 0;
		while (little[index] == big[big_walker + index] && \
				big_walker + index != len)
		{
			if (little[index + 1] == '\0')
				return (&((char *)big)[big_walker]);
			index++;
		}
		big_walker++;
	}
	return (NULL);
}
