/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:33:44 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 13:10:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Print a character to a file descriptor;
 * 
 * @param c The character to be printed;
 * @param fd The number of file descriptor;
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
