/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:23:36 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:44:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Find a node in the nbr position of the list, starting from 0;
 * 
 * @param begin_list A pointer to the first node of the list;
 * @param nbr The desired position of the node;
 * @return The node (t_list *) at the nbr position; If isn't possible, then
 * 			return NULL;
 */
t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	size_t	counter;
	t_list	*temporary;

	if (begin_list == NULL)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	counter = 0;
	temporary = begin_list;
	while (counter < nbr)
	{
		if (temporary == NULL)
			return (NULL);
		temporary = temporary->next;
		counter++;
	}
	return (temporary);
}
