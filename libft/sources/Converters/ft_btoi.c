/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:55:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 10:46:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	walk_on_whitespaces(const char *string, size_t *index);

/**
 * @brief Convert a binary string to an integer; The string is composed of
 * 			optional whitespaces, followed by a sequence of 0s and 1s; Only the
 * 			first sequence of digits is converted;
 * 
 * @param binary A pointer to the string to be converted;
 * @return The converted binary (int); 0 If the string is NULL or if the digits
 *			don't make part of the initial sequence;
 */
int	ft_btoi(const char *binary)
{
	int		number;
	size_t	index;

	if (binary == NULL)
		return (0);
	index = 0;
	walk_on_whitespaces(binary, &index);
	number = 0;
	while (binary[index] != '\0' \
			&& (binary[index] == '0' || binary[index] == '1'))
	{
		number <<= 1;
		if (binary[index] == '1')
			number |= 1;
		index++;
	}
	return (number);
}

static void	walk_on_whitespaces(const char *string, size_t *index)
{
	while (string[*index] == ' ' || string[*index] == '\t' || \
			string[*index] == '\n' || string[*index] == '\v' || \
			string[*index] == '\f' || string[*index] == '\r')
	{
		if (string[*index] == '\0')
			break ;
		else if (string[*index] >= '0' && string[*index] <= '1')
			break ;
		(*index)++;
	}
}
