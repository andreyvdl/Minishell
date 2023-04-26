/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/21 22:29:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_btree	*new_node(void *item);
static void		connect_new_node(t_btree *previous, t_btree *new, \
								int (*cmpf)(void *, void *));

/**
 * @brief Insert a node in the binary tree; The low values goes to the left and
 * 			the high or equal values goes to the right; If the root is NULL, the
 * 			function will create a new node and set it as the root;
 * 
 * @param root The root of the binary tree;
 * @param item Will be the content of the new node;
 * @param cmpf function that compares the content of the nodes;
 */
void	ft_btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree	*current;
	t_btree	*previous;

	if (item == NULL || cmpf == NULL)
		return ;
	if (*root == NULL)
	{
		*root = new_node(item);
		return ;
	}
	current = *root;
	while (current != NULL)
	{
		previous = current;
		if (cmpf(item, current->content) >= 0)
			current = current->right;
		else
			current = current->left;
	}
	connect_new_node(previous, new_node(item), cmpf);
}

static t_btree	*new_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (node == NULL)
		return (NULL);
	node->content = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void	connect_new_node(t_btree *previous, t_btree *new, \
							int (*cmpf)(void *, void *))
{
	if (cmpf(new->content, previous->content) >= 0)
		previous->right = new;
	else
		previous->left = new;
}
