/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_too_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:01:36 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:01:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	filename_too_big(char *filename)
{
	size_t	counter;

	if (filename != NULL)
	{
		while (*filename)
		{
			counter = 0;
			while (filename[counter] != '\0' && filename[counter] != '/')
				counter++;
			if (counter > FILENAME_MAX_LEN)
				return (TRUE);
			else if (filename[counter] == '\0')
				return (FALSE);
			filename += counter + 1;
		}
	}
	return (FALSE);
}
