/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:05:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/05/30 10:11:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_matrixlen(const char **matrix)
{
	size_t	size;

	size = 0;
	while (*matrix)
	{
		size++;
		matrix++;
	}
	return (size);
}
