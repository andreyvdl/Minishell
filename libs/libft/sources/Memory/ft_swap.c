/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:28:16 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/25 16:31:13 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Swaps the content of two pointers;
 * 
 * @attention If any of the pointers is NULL, the function does nothing;
 * @param pointer1 The address of the first pointer;
 * @param pointer2 The address of the second pointer;
 */
void	ft_swap(void **pointer1, void **pointer2)
{
	void	*temp;

	if (pointer1 == NULL || pointer2 == NULL)
		return ;
	temp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = temp;
}
