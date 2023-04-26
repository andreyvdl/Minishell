/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:05:47 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 14:35:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	write_string(char *s, int fd);

/**
 * @brief Print a string to the file descriptor, followed by a new line;
 * @attention If the string is NULL, it only prints a new line;
 * 
 * @param s A pointer to the string;
 * @param fd The number of the file descriptor;
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
		write_string(s, fd);
	write(fd, "\n", 1);
}

static void	write_string(char *string, int file_descriptor)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		write(file_descriptor, &string[index], 1);
		index++;
	}
}
