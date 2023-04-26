/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:52:35 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:45:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Search on the list for the nodes that match the data reference and
 * 			apply a fix on the content of that node; If any of the parameters is
 * 			NULL, the function will do nothing;
 * 
 * @param begin_list A pointer to the first node of the list;
 * @param f A pointer to the function that will be applied to the content of
 * 			the node;
 * @param data_ref A pointer to the data reference;
 * @param cmp A pointer to the function that will be used to compare the data
 * 				reference with the content of the node;
 */
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
							void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*temporary;

	if (f == NULL || data_ref == NULL || cmp == NULL || begin_list == NULL)
		return ;
	temporary = begin_list;
	while (temporary != NULL)
	{
		if (cmp(temporary->content, data_ref) == 0)
			f(temporary->content);
		temporary = temporary->next;
	}
}
