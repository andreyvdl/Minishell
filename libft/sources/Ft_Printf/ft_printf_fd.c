/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:12:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 22:40:32 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	loop_through_string_fd(int file_descriptor, const char *string, \
							va_list arg_list);

/**
 * @brief A variation of the ft_printf, it will print in a file descriptor;
 * @attention If too many characters are written it can cause an overflow;
 * 
 * @param file_descriptor The file descriptor to be printed;
 * @param string The string ot be printed;
 * @param ... The variables and/or functions return to be printed;
 * @return The total of characters printed (int); Or -1 if the string is NULL;
 */
int	ft_printf_fd(int file_descriptor, const char *string, ...)
{
	int		chars_printed;
	va_list	arg_list;

	if (string == NULL)
		return (-1);
	va_start(arg_list, string);
	chars_printed = loop_through_string_fd(file_descriptor, string, arg_list);
	va_end(arg_list);
	return (chars_printed);
}
