/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:16:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 16:22:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Prints a string to the standard output;
 * 
 * @param str A pointer to the string to be printed;
 */
void	ft_putstr(char *str)
{
	size_t	index;

	if (str == NULL)
		return ;
	index = 0;
	while (str[index] != '\0')
	{
		write(STDOUT_FILENO, &str[index], 1);
		index++;
	}
}
