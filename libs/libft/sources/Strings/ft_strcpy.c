/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:34 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 17:40:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Copies the string in src to dst (including the terminating `\0');
 * 
 * @param dst A pointer to the destination string;
 * @param src A pointer to the source string;
 * @return A pointer to the destination string (char *);
 */
char	*ft_strcpy(char *dst, char *src)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = src[index];
	return (dst);
}
