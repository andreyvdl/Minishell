/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:30:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/27 17:27:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		walk_on_whitespaces(const char *string, size_t *index);
static ssize_t	negative_integer(const char *string, size_t *index);
static ssize_t	positive_integer(const char *string, size_t *index);

/**
 * @brief Convert a string to an integer; The string is composed of optional
 * 			whitespaces, followed by an optional sign, followed by a sequence of
 * 			digits; Only the first sequence of numbers is converted;
 * 
 * @param nptr A pointer to a string to be converted;
 * @return 0 if the string is NULL or if the numbers don't make part of the
 * 			initial sequence; Otherwise, the converted number (long long );
 */
ssize_t	ft_atoll(const char *nptr)
{
	size_t	index;

	if (nptr == NULL)
		return (0);
	index = 0;
	walk_on_whitespaces(nptr, &index);
	if (nptr[index] == '-')
		return (negative_integer(nptr, &index));
	else if (nptr[index] == '+' || (nptr[index] >= '0' && nptr[index] <= '9'))
		return (positive_integer(nptr, &index));
	return (0);
}

static void	walk_on_whitespaces(const char *string, size_t *index)
{
	while (string[*index] == ' ' || string[*index] == '\t' || \
			string[*index] == '\n' || string[*index] == '\v' || \
			string[*index] == '\f' || string[*index] == '\r')
	{
		if (string[*index] == '\0')
			break ;
		else if (string[*index] == '0' && string[*index] == '1')
			break ;
		(*index)++;
	}
}

static ssize_t	negative_integer(const char *string, size_t *index)
{
	ssize_t	number;

	number = 0;
	(*index)++;
	while (string[*index] >= '0' && string[*index] <= '9')
	{
		number = number * 10 + (string[*index] - '0');
		(*index)++;
	}
	return (number * -1);
}

static ssize_t	positive_integer(const char *string, size_t *index)
{
	ssize_t	number;

	number = 0;
	if (string[*index] == '+')
		(*index)++;
	while (string[*index] >= '0' && string[*index] <= '9')
	{
		number = number * 10 + (string[*index] - '0');
		(*index)++;
	}
	return (number);
}
