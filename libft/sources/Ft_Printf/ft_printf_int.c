/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:23:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:48:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	print_negative_number(int number);
static int	print_positive_number(int number);

int	print_int(int number)
{
	if (number < 0)
		return (print_negative_number(number));
	return (print_positive_number(number));
}

static int	print_negative_number(int number)
{
	int		chars_printed;

	chars_printed = 0;
	chars_printed += (int)write(STDOUT_FILENO, "-", 1);
	if (number == INT_MIN)
	{
		chars_printed += (int)write(STDOUT_FILENO, "2147483648", 10);
		return (chars_printed);
	}
	chars_printed += print_positive_number(number * -1);
	return (chars_printed);
}

static int	print_positive_number(int number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 9)
		chars_printed += print_positive_number(number / 10);
	character = (number % 10) + '0';
	chars_printed += (int)write(STDOUT_FILENO, &character, 1);
	return (chars_printed);
}
