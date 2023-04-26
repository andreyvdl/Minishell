/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:47:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 10:02:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				print_char(char character);
int				print_char_fd(int file_descriptor, char character);
int				print_hexadecimal_lowercase(size_t number);
int				print_hexadecimal_lowercase_fd(int file_descriptor, \
												size_t number);
int				print_hexadecimal_uppercase(size_t number);
int				print_hexadecimal_uppercase_fd(int file_descriptor, \
												size_t number);
int				print_int_fd(int file_descriptor, int number);
int				print_int(int number);
int				print_ptr_fd(int file_descriptor, size_t address);
int				print_ptr(size_t address);
int				print_string(char *string);
int				print_string_fd(int file_descriptor, char *string);
int				print_unsigned_int(unsigned int number);
int				print_unsigned_int_fd(int file_descriptor, unsigned int number);
static size_t	get_string_size(const char *string);
static int		print_argument(char character, va_list arg_list);
static int		print_argument_fd(int file_descriptor, char character, \
									va_list arg_list);

int	loop_through_string(const char *string, va_list arg_list)
{
	int		chars_printed;
	size_t	index;
	size_t	string_size;

	index = 0;
	chars_printed = 0;
	string_size = get_string_size(string);
	while (index < string_size)
	{
		if (string[index] == '%')
		{
			chars_printed += print_argument(string[index + 1], arg_list);
			index++;
		}
		else
			chars_printed += (int)write(STDOUT_FILENO, &string[index], 1);
		index++;
	}
	return (chars_printed);
}

static size_t	get_string_size(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

static int	print_argument(char character, va_list arg_list)
{
	if (character == 'c')
		return (print_char(va_arg(arg_list, int)));
	else if (character == 's')
		return (print_string(va_arg(arg_list, char *)));
	else if (character == 'i' || character == 'd')
		return (print_int(va_arg(arg_list, int)));
	else if (character == 'u')
		return (print_unsigned_int(va_arg(arg_list, unsigned int)));
	else if (character == 'p')
		return (print_ptr(va_arg(arg_list, size_t)));
	else if (character == 'x')
		return (print_hexadecimal_lowercase(va_arg(arg_list, size_t)));
	else if (character == 'X')
		return (print_hexadecimal_uppercase(va_arg(arg_list, size_t)));
	else if (character == '%')
		return ((int)write(STDOUT_FILENO, "%", 1));
	return ((int)write(STDOUT_FILENO, "%", 1) + \
			(int)write(STDOUT_FILENO, &character, 1));
}

int	loop_through_string_fd(int file_descriptor, const char *string, \
							va_list arg_list)
{
	int		chars_printed;
	size_t	index;
	size_t	string_size;

	index = 0;
	chars_printed = 0;
	string_size = get_string_size(string);
	while (index < string_size)
	{
		if (string[index] == '%')
		{
			chars_printed += print_argument_fd(file_descriptor, \
												string[index + 1], arg_list);
			index++;
		}
		else
			chars_printed += (int)write(file_descriptor, &string[index], 1);
		index++;
	}
	return (chars_printed);
}

static int	print_argument_fd(int file_descriptor, char character, \
								va_list arg_list)
{
	if (character == 'c')
		return (print_char_fd(file_descriptor, va_arg(arg_list, int)));
	else if (character == 's')
		return (print_string_fd(file_descriptor, va_arg(arg_list, char *)));
	else if (character == 'i' || character == 'd')
		return (print_int_fd(file_descriptor, va_arg(arg_list, int)));
	else if (character == 'u')
		return (print_unsigned_int_fd(file_descriptor, \
										va_arg(arg_list, unsigned int)));
	else if (character == 'p')
		return (print_ptr_fd(file_descriptor, va_arg(arg_list, size_t)));
	else if (character == 'x')
		return (print_hexadecimal_lowercase_fd(file_descriptor, \
												va_arg(arg_list, size_t)));
	else if (character == 'X')
		return (print_hexadecimal_uppercase_fd(file_descriptor, \
												va_arg(arg_list, size_t)));
	else if (character == '%')
		return ((int)write(file_descriptor, "%", 1));
	else
		return ((int)write(file_descriptor, "%", 1) + \
				(int)write(file_descriptor, &character, 1));
}
