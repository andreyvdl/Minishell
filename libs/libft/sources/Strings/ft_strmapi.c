/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:53:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 11:13:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(char const *string);
static char		*create_duplicate(char const *string, size_t size, \
									char (*f)(unsigned int, char));

/**
 * @brief Applies the function f to each character of the string s to create a
 * 			new string resulting from successive applications of f;
 * 
 * @param s A pointer to the string to be iterated;
 * @param f A pointer to the function to be applied to each character;
 * @return The string created from the successive applications of f (char *);
 * 			NULL if allocation fails;
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;

	if (s == NULL || f == NULL)
		return (NULL);
	size = get_string_size(s);
	return (create_duplicate(s, size, f));
}

static size_t	get_string_size(char const *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

static char	*create_duplicate(char const *string, size_t size, \
								char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	new_string = (char *)malloc(sizeof(char) * (size + 1));
	if (new_string == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		new_string[index] = (*f)(index, string[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
