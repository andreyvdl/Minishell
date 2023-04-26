/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:44:03 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/18 17:46:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Counts the number of nodes in a list;
 * 
 * @param lst A pointer to the first node of the list;
 * @return The size of the list (size_t);
 */
size_t	ft_lstsize(t_list *lst)
{
	size_t	counter;
	t_list	*temporary;

	if (lst == NULL)
		return (0);
	temporary = lst;
	counter = 0;
	while (temporary != NULL)
	{
		temporary = temporary->next;
		counter++;
	}
	return (counter);
}
