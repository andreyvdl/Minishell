/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:20:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 21:39:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Search an item in the binary tree based on the data reference with the
 * 			function cmpf;
 * 
 * @param root A pointer to the root of the binary tree;
 * @param data_ref A pointer to the data reference;
 * @param cmpf A pointer to the function that will compare the data reference;
 * @returns NULL if the data reference can't be found or a pointer to the item
 * 			found (void *);
 */
void	*ft_btree_search_item(t_btree *root, void *data_ref, \
								int (*cmpf)(void *, void *))
{
	void	*content;

	content = NULL;
	if (root == NULL || data_ref == NULL || cmpf == NULL)
		return (NULL);
	content = ft_btree_search_item(root->left, data_ref, cmpf);
	if (content != NULL)
		return (content);
	if (cmpf(root->content, data_ref) == 0)
		return (root->content);
	content = ft_btree_search_item(root->right, data_ref, cmpf);
	if (content != NULL)
		return (content);
	return (NULL);
}
