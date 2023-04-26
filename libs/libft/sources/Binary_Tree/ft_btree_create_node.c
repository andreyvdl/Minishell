/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:29:04 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/17 22:31:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Creates a new node of the binary tree;
 * 
 * @param item A pointer to the content to be put in the node;
 * @return A pointer to the new node;
 */
t_btree	*ft_btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	if (new == NULL)
		return (NULL);
	new->content = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
