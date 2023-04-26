/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:02:05 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 22:36:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Get the absolute value of a number if it is a negative;
 * 
 * @param number The number to be converted to absolute;
 * @return The number in absolute form;
**/
int	ft_absolute_number(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}
