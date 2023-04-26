/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:04:22 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:47:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Compares the string pointed to by s1 to the string pointed to by s2;
 * 
 * @param s1 A pointer to the first string to be compared;
 * @param s2 A pointer to the second string to be compared;
 * @return 0 if the strings are identical, otherwise returns the difference
 * 			between the first two differing bytes (int);
 */
int	ft_strcmp(char *s1, char *s2)
{
	int		difference;
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		difference = (int)s1[index] - (int)s2[index];
		if (difference != 0)
			return (difference);
		index++;
	}
	difference = (int)s1[index] - (int)s2[index];
	return (difference);
}
