/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:15:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/26 13:47:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	analize_uppercase(char *string, size_t index);
static void	analize_lowercase(char *string, size_t index);

/**
 * @brief Capitalizes the first letter of each word in a string;
 * 
 * @param str A pointer to the string;
 * @return The string capitalized (char *);
 */
char	*ft_strcapitalize(char *str)
{
	size_t	index;

	if (str == NULL)
		return (NULL);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			analize_uppercase(str, index);
		else if (str[index] >= 'a' && str[index] <= 'z')
			analize_lowercase(str, index);
		index++;
	}
	return (str);
}

static void	analize_uppercase(char *string, size_t index)
{
	if (index == 0)
		return ;
	else if (string[index - 1] != ' ' && string[index - 1] != '\n' && \
			string[index - 1] != '\t' && string[index - 1] != '\v' && \
			string[index - 1] != '\f' && string[index - 1] != '\r')
		string[index] += 32;
}

static void	analize_lowercase(char *string, size_t index)
{
	if (index == 0)
		string[index] -= 32;
	else if (string[index - 1] == ' ' || string[index - 1] == '\n' || \
			string[index - 1] == '\t' || string[index - 1] == '\v' || \
			string[index - 1] == '\f' || string[index - 1] == '\r')
		string[index] -= 32;
}
