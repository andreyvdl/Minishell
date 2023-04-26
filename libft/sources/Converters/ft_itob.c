/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:47:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 11:25:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_size(int number);
static char	*allocate_and_fill(int nbr, int size);

/**
 * @brief Converts an integer to a binary string;
 * 
 * @attention The size of the string is based from the MSB of the integer;
 *
 * @param nbr the integer to be converted;
 * @return NULL if the allocation fails or if nbr is negative, otherwise the
 * 			string (char *);
 */
char	*ft_itob(int nbr)
{
	int	size;

	if (nbr < 0)
		return (NULL);
	size = get_size(nbr);
	return (allocate_and_fill(nbr, size));
}

static int	get_size(int number)
{
	int	size;

	size = 1;
	while (number > 1)
	{
		number /= 2;
		size++;
	}
	return (size);
}

static char	*allocate_and_fill(int nbr, int size)
{
	char	*array;

	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	array[size] = '\0';
	size--;
	while (size != -1)
	{
		array[size] = nbr % 2 + '0';
		nbr /= 2;
		size--;
	}
	return (array);
}
