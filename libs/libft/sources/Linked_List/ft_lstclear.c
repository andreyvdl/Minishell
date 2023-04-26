/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:28:36 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:46:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Deletes and frees the entire list; If the list is NULL, nothing will
 * 			happen;
 * 
 * @param lst The address to the first node of a list;
 * @param del A pointer to a funciton that will clear the content of the node;
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*free_this;

	while (*lst != NULL)
	{
		free_this = *lst;
		*lst = (*lst)->next;
		del(free_this->content);
		free(free_this);
	}
	lst = NULL;
}
