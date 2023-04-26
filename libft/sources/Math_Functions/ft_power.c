/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:51:49 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 13:43:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static double	validate_zeros(double number, int exponent);
static double	negative_exponent(double number, int exponent);
static double	positive_exponent(double number, int exponent);

/**
 * @brief Make the power of number by exponent;
 * 
 * @param number The number to be powered;
 * @param exponent The exponent of the power;
 * @return 1=> IF number is exactly 0 return 0;
 * 			2=> IF exponent is 0 return 1;
 * 			3=> IF exponent is negative and number is exactly 0 return number
 * 				(IT'S IMPOSSIBLE TO DIVIDE BY ZERO);
 * 			4=> IF exponent is negative return the result of the division of 1
 * 				by number using exponent as an iterator (double);
 * 			5=> IF exponent is positive return the result of the multiplication
 * 				of 1 by number using exponent as an iterator (double);
 */
double	ft_power(double number, int exponent)
{
	if (number == 0 || exponent == 0)
		return (validate_zeros(number, exponent));
	else if (exponent < 0)
		return (negative_exponent(number, exponent));
	return (positive_exponent(number, exponent));
}

static double	validate_zeros(double number, int exponent)
{
	if (number == 0 && exponent < 0)
		return (number);
	else if (exponent == 0)
		return (1);
	return (0);
}

static double	negative_exponent(double number, int exponent)
{
	double	total;

	total = 1;
	while (exponent < 0)
	{
		total = total / number;
		exponent++;
	}
	return (total);
}

static double	positive_exponent(double number, int exponent)
{
	double	total;

	total = 1;
	while (exponent > 0)
	{
		total = total * number;
		exponent--;
	}
	return (total);
}
