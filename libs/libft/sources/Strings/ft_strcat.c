/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:08:22 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:47:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(char *string);

/**
 * @brief Concatenates two strings; The destiny string must have enough space to
 * 			receive the source string;
 * 
 * @param dest A pointer to the destiny string;
 * @param src A pointer to the string that will be added to the destiny string;
 * @return A pointer to the concatenated destiny string (char *);
 */
char	*ft_strcat(char *dest, char *src)
{
	size_t	dest_size;
	size_t	index;

	dest_size = get_string_size(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[dest_size + index] = src[index];
		index++;
	}
	dest[dest_size + index] = '\0';
	return (dest);
}

static size_t	get_string_size(char *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}
