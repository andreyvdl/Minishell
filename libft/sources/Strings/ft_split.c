/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:08:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 22:34:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		**allocate_strings(char const *string, char delimiter, \
									char ***matrix, size_t words);
static void		clear_matrix(char ***matrix, size_t line);
static void		copy_word(char const *string, char **word, char delimiter, \
							size_t *index);
static size_t	get_word_size(char const *string, char delimiter, size_t index);

/**
 * @brief Allocates a matrix and split a string into words using a delimiter;
 * 
 * @param s A pointer to the string to be split;
 * @param c The delimiter character;
 * @return A pointer to the matrix of strings (char **); Otherwise NULL if 
 * 			allocation fails or if the string is NULL;
 */
char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	index;
	size_t	words;

	if (s == NULL)
		return (NULL);
	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index] != '\0')
			words++;
		while (s[index] != c && s[index] != '\0')
			index++;
	}
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	return (allocate_strings(s, c, &matrix, words));
}

static char	**allocate_strings(char const *string, char delimiter, \
								char ***matrix, size_t words)
{
	size_t	index;
	size_t	line;

	index = 0;
	line = 0;
	while (string[index] != '\0' && line < words)
	{
		while (string[index] == delimiter)
			index++;
		*matrix[line] = (char *)malloc(get_word_size(string, delimiter, index) \
										+ 1);
		if (*matrix[line] == NULL)
		{
			clear_matrix(matrix, line);
			return (NULL);
		}
		copy_word(string, &(*matrix[line]), delimiter, &index);
		line++;
	}
	(*matrix)[line] = NULL;
	return (*matrix);
}

static size_t	get_word_size(char const *string, char delimiter, size_t index)
{
	size_t	size;

	size = 0;
	while (string[index + size] != delimiter && string[index + size] != '\0')
		size++;
	return (size);
}

static void	clear_matrix(char ***matrix, size_t line)
{
	size_t	index;

	index = 0;
	while (index < line)
	{
		free(*matrix[index]);
		index++;
	}
	free(*matrix);
}

static void	copy_word(char const *string, char **word, char delimiter, \
						size_t *index)
{
	size_t	position;

	position = 0;
	while (string[*index] != delimiter && string[*index] != '\0')
	{
		(*word)[position] = string[*index];
		position++;
		(*index)++;
	}
	(*word)[position] = '\0';
}
