/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:55:55 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 19:50:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	print_address_as_hexadecimal(size_t address);
static char	get_hexadecimal_digit(size_t address);

int	print_ptr(size_t address)
{
	if (address == 0)
		return ((int)write(STDOUT_FILENO, "(nil)", 5));
	return (print_address_as_hexadecimal(address));
}

static int	print_address_as_hexadecimal(size_t address)
{
	int		chars_printed;
	char	character;

	chars_printed = 0;
	if (address > 15)
		chars_printed += print_address_as_hexadecimal(address / 16);
	character = get_hexadecimal_digit(address % 16);
	chars_printed += (int)write(STDOUT_FILENO, &character, 1);
	return (chars_printed);
}

static char	get_hexadecimal_digit(size_t address)
{
	char	character;

	if (address < 10)
		character = address + '0';
	else
		character = address + 'a' - 10;
	return (character);
}
