/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_setup_global.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash)
{
	int		status;

	status = REDI_OK;
	g_shell.command = (t_command *)ft_calloc(nbr_cmds + 1, sizeof(t_command));
	g_shell.id = 0;
	g_shell.nbr_sons = nbr_cmds;
	g_shell.pipeline_rest = cmds;
	g_shell.envp = hash_to_matrix(hash);
	while (g_shell.id < nbr_cmds)
	{
		status = fill_son_orders(g_shell.command, *cmds);
		if (status == REDI_SIGNAL)
			return (status);
		g_shell.id++;
		cmds++;
	}
	g_shell.id = 0;
	return (status);
}
