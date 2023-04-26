/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:42:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 17:49:32 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(const char *string);

/**
 * @brief Duplicates a string;
 * 
 * @param s A pointer to the string to be duplicated;
 * @return A pointer to the new string (char *); Or NULL if the allocation fails;
 */
char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	index;

	copy = (char *)malloc((get_string_size(s) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		copy[index] = s[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

static size_t	get_string_size(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}
