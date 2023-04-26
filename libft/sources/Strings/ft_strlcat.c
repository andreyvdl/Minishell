/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:28:59 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:32 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(const char *str);

/**
 * @brief Concatenates two strings; The destiny string must have enough space to
 * 			receive the source string;
 * 
 * @param dst A pointer to the destiny string;
 * @param src A pointer to the string that will be added to the destiny string;
 * @param size The total size of the new string (size - 1);
 * @return The total size of the new string (dst + size) (size_t);
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	index;

	dest_size = get_string_size(dst);
	if (size == 0 || dest_size > size - 1)
		return (get_string_size(src) + size);
	index = 0;
	while (dest_size + index < size - 1 && src[index] != '\0')
	{
		dst[dest_size + index] = src[index];
		index++;
	}
	dst[dest_size + index] = '\0';
	return (dest_size + get_string_size(src));
}

static size_t	get_string_size(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}
