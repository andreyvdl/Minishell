/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:15:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 22:13:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_string(char *string)
{
	size_t	index;
	int		chars_printed;

	if (string == NULL)
		return ((int)write(STDOUT_FILENO, "(null)", 6));
	index = 0;
	chars_printed = 0;
	while (string[index] != '\0')
	{
		write(STDOUT_FILENO, &string[index], 1);
		chars_printed++;
		index++;
	}
	return (chars_printed);
}

int	print_string_fd(int file_descriptor, char *string)
{
	size_t	index;
	int		chars_printed;

	if (string == NULL)
		return ((int)write(file_descriptor, "(null)", 6));
	index = 0;
	chars_printed = 0;
	while (string[index] != '\0')
	{
		write(file_descriptor, &string[index], 1);
		chars_printed++;
		index++;
	}
	return (chars_printed);
}
