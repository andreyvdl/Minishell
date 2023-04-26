/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:24:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 13:54:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dst;
 * 
 * @param dst A pointer to the destiny memory area;
 * @param src A pointer to the source memory area;
 * @param n The maximum number of bytes to copy;
 * @return A pointer to the destination memory area (void *);
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*temporary_destiny;
	unsigned char	*temporary_source;

	if (dst == NULL || src == NULL)
		return (dst);
	temporary_destiny = (unsigned char *)dst;
	temporary_source = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		temporary_destiny[index] = temporary_source[index];
		index++;
	}
	return (dst);
}
