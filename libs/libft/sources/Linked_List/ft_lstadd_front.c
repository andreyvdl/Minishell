/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:55:00 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:46:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Add a new node at the beginning of the list; If the list is NULL, the
 * 			new node will be the first node; If the new node is NULL, nothing
 * 			will happen;
 * 
 * @param lst The address of a pointer to the first link of a list;
 * @param new The pointer to the new node to be added to the list;
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
