/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:47:48 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 22:15:07 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_unsigned_int(unsigned int number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 9)
		chars_printed += print_unsigned_int(number / 10);
	character = (number % 10) + '0';
	chars_printed += (int)write(STDOUT_FILENO, &character, 1);
	return (chars_printed);
}

int	print_unsigned_int_fd(int file_descriptor, unsigned int number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 9)
		chars_printed += print_unsigned_int_fd(file_descriptor, number / 10);
	character = (number % 10) + '0';
	chars_printed += (int)write(file_descriptor, &character, 1);
	return (chars_printed);
}
