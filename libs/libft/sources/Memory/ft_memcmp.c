/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:54:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 12:21:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Compares bytes of the memory area s1 against memory area s2, both are
 *			assumed to be n bytes long;
 * 
 * @param s1 A pointer to the first memory area to be compared;
 * @param s2 A pointer to the second memory area to be compared;
 * @param n The maximum
 * @return The difference between the two first differing bytes (int)
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*temporary1;
	unsigned char	*temporary2;

	if (n == 0)
		return (0);
	temporary1 = (unsigned char *)s1;
	temporary2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (temporary1[index] != temporary2[index])
			return (temporary1[index] - temporary2[index]);
		index++;
	}
	return (0);
}
