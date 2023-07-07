/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:05:20 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:05:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	isbuiltin(char *check)
{
	int		i;
	char	**builtin;

	builtin = ft_split(BUILTIN, ' ');
	i = 0;
	while (check != NULL && builtin[i] != NULL)
	{
		if (ft_strcmp(builtin[i], check) == 0)
		{
			ft_free_matrix((void **)builtin);
			return (TRUE);
		}
		i++;
	}
	ft_free_matrix((void **)builtin);
	return (FALSE);
}
