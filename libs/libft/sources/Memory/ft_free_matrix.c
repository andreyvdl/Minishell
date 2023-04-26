/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:17:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 11:25:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Free a matrix and set every pointer to NULL;
 * 
 * @param matrix A pointer to the address of the matrix to be freed;
 */
void	ft_free_matrix(void ***matrix)
{
	size_t	line;

	line = 0;
	if (*matrix != NULL && **matrix != NULL)
	{
		while (*matrix[line] != NULL)
		{
			free(*matrix[line]);
			*matrix[line] = NULL;
			line++;
		}
		free(*matrix);
		*matrix = NULL;
	}
}
