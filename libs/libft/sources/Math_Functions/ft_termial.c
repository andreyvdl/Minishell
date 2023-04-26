/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:48:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 00:01:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Calculates the termial of a given number;
 * @warning Big numbers can cause an overflow;
 * 
 * @param n The number to calculate the termial;
 * @return The total of the termial (unsigned int);
 */
unsigned int	ft_termial(unsigned int n)
{
	unsigned int	total;

	total = 1;
	while (n > 1)
	{
		total += n;
		n--;
	}
	return (total);
}
