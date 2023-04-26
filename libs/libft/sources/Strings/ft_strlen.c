/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:51:20 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 09:53:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Calculate the length of the string s;
 * 
 * @param s A pointer to the string to be measured;
 * @return The length of the string (size_t); If s is NULL, returns 0;
 */
size_t	ft_strlen(const char *s)
{
	size_t	index;

	if (s == NULL)
		return (0);
	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
