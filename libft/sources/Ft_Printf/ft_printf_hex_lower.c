/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:32:17 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:48:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	get_hex_lowercase(size_t number);

int	print_hexadecimal_lowercase(size_t number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 15)
		chars_printed += print_hexadecimal_lowercase(number / 16);
	character = get_hex_lowercase(number % 16);
	chars_printed += (int)write(STDOUT_FILENO, &character, 1);
	return (chars_printed);
}

static char	get_hex_lowercase(size_t number)
{
	char	character;

	if (number < 10)
		character = number + '0';
	else
		character = number + 'a' - 10;
	return (character);
}

int	print_hexadecimal_lowercase_fd(int file_descriptor, size_t number)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (number > 15)
		chars_printed += print_hexadecimal_lowercase_fd(file_descriptor, \
														number / 16);
	character = get_hex_lowercase(number % 16);
	chars_printed += (int)write(file_descriptor, &character, 1);
	return (chars_printed);
}
