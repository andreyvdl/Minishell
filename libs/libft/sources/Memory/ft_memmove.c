/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:48:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	copy_front_to_end(unsigned char *destiny, unsigned char *source, \
								size_t n);
static void	copy_end_to_front(unsigned char *destiny, unsigned char *source, \
								size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dst;
 * 
 * @attention If the memory areas overlap, it will move bytes backwards;
 * 
 * @param dst A pointer to the memory area of destiny;
 * @param src A pointer to the memory area of source;
 * @param n The number of bytes to be copied;
 * @return A pointer to the memory area of destiny (void *);
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temporary_destiny;
	unsigned char	*temporary_source;

	if (dst == NULL || src == NULL)
		return (dst);
	temporary_destiny = (unsigned char *)dst;
	temporary_source = (unsigned char *)src;
	if (temporary_destiny < temporary_source)
		copy_front_to_end(temporary_destiny, temporary_source, n);
	else
		copy_end_to_front(temporary_destiny, temporary_source, n);
	return (dst);
}

static void	copy_front_to_end(unsigned char *destiny, unsigned char *source, \
								size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		destiny[index] = source[index];
		index++;
	}
}

static void	copy_end_to_front(unsigned char *destiny, unsigned char *source, \
								size_t n)
{
	while (n > 0)
	{
		destiny[n] = source[n];
		n--;
	}
}
