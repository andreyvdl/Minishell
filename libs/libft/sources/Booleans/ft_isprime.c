/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:43 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 17:41:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks if the number is prime;
 * 
 * @param nb the number to be checked;
 * @return true if the number is prime; otherwise, false;
 */
int	ft_isprime(int nb)
{
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (true);
	else if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
		return (false);
	return (true);
}
