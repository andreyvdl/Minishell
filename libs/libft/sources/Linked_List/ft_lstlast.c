/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:23:29 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:49:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Find the last node of the list;
 * 
 * @param lst A pointer to the first node of the list;
 * @return The last node (t_list *) of the list; If the list is empty, then
 * 			return NULL;
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temporary;

	if (lst == NULL)
		return (NULL);
	temporary = lst;
	while (temporary->next != NULL)
		temporary = temporary->next;
	return (temporary);
}
