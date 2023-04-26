/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:44:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 21:53:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_matrix_size(char **matrix);
static size_t	get_string_size(char *string);
static void		clear_matrix(char ***matrix);
static void		malloc_and_duplicate(char **matrix, char **copy, size_t line);

/**
 * @brief Duplicates a matrix of strings;
 * 
 * @param matrix A pointer to the matrix to be duplicated;
 * @return A copy of the matrix (char **);
 */
char	**ft_matrixdup(char **matrix)
{
	char	**copy;
	size_t	line;

	if (matrix == NULL || *matrix == NULL)
		return (NULL);
	copy = (char **)malloc((get_matrix_size(matrix) + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	line = 0;
	while (matrix[line] != NULL)
	{
		malloc_and_duplicate(matrix, copy, line);
		if (copy[line] == NULL)
		{
			clear_matrix(&copy);
			return (NULL);
		}
		line++;
	}
	copy[line] = NULL;
	return (copy);
}

static size_t	get_matrix_size(char **matrix)
{
	size_t	size;

	size = 0;
	while (matrix[size] != NULL)
		size++;
	return (size);
}

static void	malloc_and_duplicate(char **matrix, char **copy, size_t line)
{
	size_t	index;

	copy[line] = (char *)malloc((get_string_size(matrix[line]) + 1) * \
								sizeof(char));
	if (copy[line] == NULL)
		return ;
	index = 0;
	while (matrix[line][index] != '\0')
	{
		copy[line][index] = matrix[line][index];
		index++;
	}
	copy[line][index] = '\0';
}

static size_t	get_string_size(char *string)
{
	size_t	size;

	size = 0;
	while (string[size] != '\0')
		size++;
	return (size);
}

static void	clear_matrix(char ***matrix)
{
	size_t	line;

	line = 0;
	while (*matrix[line] != NULL)
	{
		free(*matrix[line]);
		line++;
	}
	free(*matrix);
}
