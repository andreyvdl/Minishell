/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:40:26 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 16:33:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Writes n zeroed bytes to the memory area s;
 * 
 * @param s A pointer to the memory area;
 * @param n The number of bytes to be written;
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*temporary;

	if (s == NULL || n == 0)
		return ;
	temporary = (char *)s;
	index = 0;
	while (index < n)
	{
		temporary[index] = '\0';
		index++;
	}
}
