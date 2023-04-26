/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:03:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 13:16:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_decimal_value(char character);
static int	convert_hexadecimal(const char *hexadecimal, size_t index);
static void	walk_on_whitespaces(const char *string, size_t *index);

/**
 * @brief Convert a hexadecimal string to an integer; The string is composed of
 * 			optional whitespaces, followed by an optional indicator of
 * 			hexadecimal, followed by a sequence of digits or letters from A to
 * 			F;
 * 
 * @param hexadecimal A pointer to the string to be converted;
 * @return 0 if the string is NULL or if the digits and letters don't make part
 * 			of the initial sequence; Otherwise, the converted number (int);
 */
int	ft_htoi(const char *hexadecimal)
{
	size_t	index;

	if (hexadecimal == NULL)
		return (0);
	index = 0;
	walk_on_whitespaces(hexadecimal, &index);
	if (hexadecimal[index] == '0' \
		&& (hexadecimal[index + 1] == 'x' || hexadecimal[index + 1] == 'X'))
		index += 2;
	return (convert_hexadecimal(hexadecimal, index));
}

static void	walk_on_whitespaces(const char *string, size_t *index)
{
	while (string[*index] == ' ' || string[*index] == '\t' || \
			string[*index] == '\n' || string[*index] == '\v' || \
			string[*index] == '\f' || string[*index] == '\r')
	{
		if (string[*index] == '\0')
			break ;
		else if ((string[*index] >= 'A' && string[*index] <= 'F') \
				|| (string[*index] >= 'a' && string[*index] <= 'f') \
				|| (string[*index] >= '0' && string[*index] <= '9'))
			break ;
		(*index)++;
	}
}

static int	get_decimal_value(char character)
{
	if (character >= '0' && character <= '9')
		return (character - '0');
	else if (character >= 'a' && character <= 'f')
		return (character - 'a' + 10);
	else if (character >= 'A' && character <= 'F')
		return (character - 'A' + 10);
	return (-1);
}

static int	convert_hexadecimal(const char *hexadecimal, size_t index)
{
	int	temporary;
	int	number;

	number = 0;
	while (hexadecimal[index] != '\0')
	{
		temporary = get_decimal_value(hexadecimal[index]);
		if (temporary == -1)
			break ;
		number = number * 16 + temporary;
		index++;
	}
	return (number);
}
