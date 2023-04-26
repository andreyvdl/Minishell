/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:49:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Iterates through a list and applies a fix with the function f; If the
 * 			list is empty, nothing happens;
 * 
 * @param lst A pointer to the first node of the list;
 * @param f A pointer to the function that applies the fix;
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temporary;

	if (lst == NULL)
		return ;
	temporary = lst;
	while (temporary != 0x0)
	{
		f(temporary->content);
		temporary = temporary->next;
	}
}
