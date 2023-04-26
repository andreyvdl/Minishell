/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:50:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/19 21:52:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		add_to_the_end(t_list **list, t_list *new_node);
static t_list	*create_new_node(char *string);

/**
 * @brief Creates a new list with the strings passed as parameters;
 * 
 * @param size The size of the array of strings;
 * @param strs A pointer to an array of pointers to strings;
 * @return A pointer to the first node of the list (t_list *);
 */
t_list	*ft_list_push_strs(size_t size, char **strs)
{
	t_list	*list;

	if (strs == NULL || *strs == NULL)
		return (NULL);
	list = NULL;
	while (size > -1)
	{
		add_to_the_end(&list, create_new_node(strs[size]));
		size--;
	}
	return (list);
}

static void	add_to_the_end(t_list **list, t_list *new_node)
{
	t_list	*temporary;

	if (new_node == NULL)
		return ;
	else if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	temporary = *list;
	while (temporary->next != NULL)
		temporary = temporary->next;
	temporary->next = new_node;
}

static t_list	*create_new_node(char *string)
{
	t_list	*new_node;

	if (string == NULL)
		return (NULL);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = string;
	new_node->next = NULL;
	return (new_node);
}
