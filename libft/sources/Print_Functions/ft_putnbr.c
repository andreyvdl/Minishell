/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:50:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 23:25:40 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_negative_number(int number);
static void	print_positive_number(int number);

/**
 * @brief Prints the integer n to the standard output;
 * 
 * @param n The number to be printed;
 */
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		print_negative_number(n);
		return ;
	}
	print_positive_number(n);
}

static void	print_negative_number(int number)
{
	write(STDOUT_FILENO, "-", 1);
	if (number == INT_MIN)
	{
		write(STDOUT_FILENO, "2147483648", 10);
		return ;
	}
	print_positive_number(number * -1);
}

static void	print_positive_number(int number)
{
	char	character;

	if (number > 9)
		print_positive_number(number / 10);
	character = (number % 10) + '0';
	write(STDOUT_FILENO, &character, 1);
}
