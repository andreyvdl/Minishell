/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:43:35 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 16:33:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	*malloc_and_zeroed(size_t limit);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and
 * 			put zeros in all positions;
 * 
 * @param nmemb The number of member of the array;
 * @param size The size of each member of the array;
 * @return A pointer to the new array (void *); Or NULL if allocation fails or
 * 			if the multiplication of nmemb and size exceeds the limit of size_t
 * 			or if nmemb and/or size is 0;
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	limit;

	if (nmemb == 0 || size == 0)
		return (NULL);
	limit = nmemb * size;
	if (limit / size != nmemb || limit / nmemb != size)
		return (NULL);
	return (malloc_and_zeroed(limit));
}

static void	*malloc_and_zeroed(size_t limit)
{
	char	*array;
	size_t	index;

	array = (char *)malloc(limit);
	if (array == NULL)
		return (NULL);
	index = 0;
	while (index < limit)
	{
		array[index] = '\0';
		index++;
	}
	return ((void *)array);
}
