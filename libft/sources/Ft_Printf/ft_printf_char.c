/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:11:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 20:20:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	print_char(char character)
{
	return ((int)write(STDOUT_FILENO, &character, 1));
}

int	print_char_fd(int file_descriptor, char character)
{
	return ((int)write(file_descriptor, &character, 1));
}
