/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:24:28 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 11:12:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(const char *string);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src;
 * 
 * @param dst A pointer to the destiny string;
 * @param src A pointer to the string that will be copied to the destiny string;
 * @param size The maximum copy size (size - 1);
 * @return The size of the new string (size_t);
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
		return (get_string_size(src));
	index = 0;
	while (index + 1 < size && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (get_string_size(src));
}

static size_t	get_string_size(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}
