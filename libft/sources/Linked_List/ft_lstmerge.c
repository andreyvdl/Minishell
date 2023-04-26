/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:56:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:49:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*reach_end_of_list(t_list *list);

/**
 * @brief Merge the end of a list to the start of another list; If the first
 * 			list is NULL the second list becomes the first, if the second list
 * 			is NULL nothing happens;
 * 
 * @param begin_list1 The address of the first node of the first list;
 * @param begin_list2 A pointer to the first node of the second list;
 */
void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (begin_list2 == NULL)
		return ;
	else if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	current = reach_end_of_list(*begin_list1);
	current->next = begin_list2;
}

static t_list	*reach_end_of_list(t_list *list)
{
	t_list	*walker;

	walker = list;
	while (walker->next != NULL)
		walker = walker->next;
	return (walker);
}
