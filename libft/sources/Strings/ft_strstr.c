/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 16:25:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string to_find in
 * 			the string str;
 * 
 * @param str A pointer to the string to be scanned;
 * @param to_find A pointer to the string to be found;
 * @return The pointer to the first occurrence of to_find in str (char *); Or
 * 			NULL if to_find does not appear in str; Or str if to_find is empty;
 */
char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	str_walker;
	size_t	index;

	if ((to_find[0] == '\0' && str[0] == '\0') || to_find[0] == '\0')
		return ((char *)str);
	str_walker = 0;
	while (str[str_walker] != '\0')
	{
		index = 0;
		while (to_find[index] == str[str_walker + index])
		{
			if (to_find[index + 1] == '\0')
				return (&((char *)str)[str_walker]);
			index++;
		}
		str_walker++;
	}
	return (NULL);
}
