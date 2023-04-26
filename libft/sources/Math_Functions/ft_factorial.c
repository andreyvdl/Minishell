/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:39:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:52:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Calculates the factorial of a given number; The number must be a 
 * 			spositive integer;
 * @warning If n is higher than 12 it will result in an overflow; Remeber the
 * 			limit of unsigned int is 4.294.967.295;
 * 
 * @param n The number to calculate the factorial;
 * @return The total of the factorial (unsigned int);
 */
unsigned int	ft_factorial(unsigned int n)
{
	unsigned int	total;

	if (n == 1 || n == 0)
		return (1);
	total = 1;
	while (n > 1)
	{
		total *= n;
		n--;
	}
	return (total);
}
