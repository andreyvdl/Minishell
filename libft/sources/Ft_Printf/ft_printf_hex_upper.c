/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:48:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 20:22:32 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	get_hex_uppercase(size_t number);

int	print_hexadecimal_uppercase(size_t number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 15)
		chars_printed += print_hexadecimal_uppercase(number / 16);
	character = get_hex_uppercase(number % 16);
	chars_printed += (int)write(STDOUT_FILENO, &character, 1);
	return (chars_printed);
}

static char	get_hex_uppercase(size_t number)
{
	char	character;

	if (number < 10)
		character = number + '0';
	else
		character = number + 'A' - 10;
	return (character);
}

int	print_hexadecimal_uppercase_fd(int file_descriptor, size_t number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 15)
		chars_printed += print_hexadecimal_uppercase_fd(file_descriptor, \
														number / 16);
	character = get_hex_uppercase(number % 16);
	chars_printed += (int)write(file_descriptor, &character, 1);
	return (chars_printed);
}
