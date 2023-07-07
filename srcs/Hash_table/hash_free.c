/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:37:57 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/07 16:37:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_this_node(t_node *node)
{
	if (node->next != NULL)
		free_this_node(node->next);
	free(node->key);
	free(node->value);
	free(node);
}

void	free_hash(t_hash *hash)
{
	size_t	index;
	t_node	*temp;

	index = 0;
	while (index < HASH_SIZE)
	{
		temp = hash->list[index];
		if (temp)
			free_this_node(temp);
		index++;
	}
	free(hash);
}
