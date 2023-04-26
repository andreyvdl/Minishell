/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:45:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:44:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Find a node in the list that matches the data_ref;
 * 
 * @param begin_list A pointer to the begin of the list;
 * @param data_ref The data to be compared;
 * @param cmp The function to compare the data;
 * @return A pointer to the node (t_list *) that matches the data_ref; If isn't
 * 			possible, then return NULL;
 */
t_list	*ft_list_find(t_list *begin_list, void *data_ref, \
						int (*cmp)(void *, void *))
{
	t_list	*temporary;

	if (begin_list == NULL || data_ref == NULL || cmp == NULL)
		return (NULL);
	temporary = begin_list;
	while (temporary != NULL)
	{
		if (cmp(temporary->content, data_ref) == 0)
			return (temporary);
		temporary = temporary->next;
	}
	return (NULL);
}
