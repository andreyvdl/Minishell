/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:03:56 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 13:09:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Print a character to the standard output;
 * 
 * @param c The character to be printed;
 */
void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
