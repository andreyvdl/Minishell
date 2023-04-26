/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:49:46 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 21:56:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	print_negative_number_fd(int file_descriptor, int number);
static int	print_positive_number_fd(int file_descriptor, int number);

int	print_int_fd(int file_descriptor, int number)
{
	if (number < 0)
		return (print_negative_number_fd(file_descriptor, number));
	return (print_positive_number_fd(file_descriptor, number));
}

static int	print_negative_number_fd(int file_descriptor, int number)
{
	int		chars_printed;

	chars_printed = 0;
	chars_printed += (int)write(file_descriptor, "-", 1);
	if (number == INT_MIN)
	{
		chars_printed += (int)write(file_descriptor, "2147483648", 10);
		return (chars_printed);
	}
	chars_printed += print_positive_number_fd(file_descriptor, number * -1);
	return (chars_printed);
}

static int	print_positive_number_fd(int file_descriptor, int number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 9)
		chars_printed += print_positive_number_fd(file_descriptor, number / 10);
	character = (number % 10) + '0';
	chars_printed += (int)write(file_descriptor, &character, 1);
	return (chars_printed);
}
