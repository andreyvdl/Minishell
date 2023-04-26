/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:27:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 23:10:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	loop_through_string(const char *string, va_list arg_list);

/**
 * @brief A variation of the ft_printf, it will print a new line at the end;
 * @attention If too many characters are written it can cause an overflow;
 * 
 * @param string The string ot be printed;
 * @param ... The variables and/or functions return to be printed;
 * @return The total of characters printed (int); Or -1 if the string is NULL;
 */
int	ft_printf_ln(const char *string, ...)
{
	int		chars_printed;
	va_list	arg_list;

	if (string == NULL)
		return (-1);
	va_start(arg_list, string);
	chars_printed = loop_through_string(string, arg_list);
	va_end(arg_list);
	chars_printed += (int)write(STDOUT_FILENO, "\n", 1);
	return (chars_printed);
}
