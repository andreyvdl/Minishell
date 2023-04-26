/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:53:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 15:42:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Compares the first n bytes of s1 and s2;
 * 
 * @param s1 A pointer to the first string to be compared;
 * @param s2 A pointer to the second string to be compared;
 * @param n The maximum number of characters to be compared;
 * @return A number based on the difference between s1 and s2 (int); 0 if there
 * 			is no difference or if n is 0;
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		difference;
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		difference = (int)s1[index] - (int)s2[index];
		if (difference != 0)
			return (difference);
		index++;
	}
	return (difference);
}
