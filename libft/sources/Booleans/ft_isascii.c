/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:01:05 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 17:21:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks for an ASCII character;
 * 
 * @param c the character to be checked;
 * @return true if the character is an ASCII character; otherwise, false;
 */
int	ft_isascii(int c)
{
	const char	del_ascii = 127;

	if (c >= '\0' && c <= del_ascii)
		return (true);
	return (false);
}
