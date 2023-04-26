/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 17:00:53 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Checks for an alphanumeric character;
 * 
 * @param c The character to be checked;
 * @return If the character is alphanumeric, returns true; otherwise, false;
 */
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || \
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (true);
	return (false);
}
