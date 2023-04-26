/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:11:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 14:21:24 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_negative_number(int number, int file_descriptor);
static void	print_positive_number(int number, int file_descriptor);

/**
 * @brief Prints the integer n to the given file descriptor;
 * 
 * @param n The integer to be printed;
 * @param fd The number of the file descriptor;
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		print_negative_number(n, fd);
		return ;
	}
	print_positive_number(n, fd);
}

static void	print_negative_number(int number, int file_descriptor)
{
	char	character;

	write(file_descriptor, "-", 1);
	while (number < 0)
	{
		character = (number % 10) * -1 + '0';
		write(file_descriptor, &character, 1);
		number /= 10;
	}
}

static void	print_positive_number(int number, int file_descriptor)
{
	char	character;

	while (number > 0)
	{
		character = number % 10 + '0';
		write(file_descriptor, &character, 1);
		number /= 10;
	}
}
