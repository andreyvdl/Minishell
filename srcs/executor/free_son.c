/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_son.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:15:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:15:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_son(void)
{
	size_t	looper;

	looper = 0;
	ft_free_matrix((void **)g_shell.envp);
	free_hash(g_shell.hash);
	while (looper < g_shell.nbr_sons)
	{
		ft_free_matrix((void **)g_shell.command[looper].argv);
		if (g_shell.command[looper].wr_here > STDOUT_FILENO)
			close(g_shell.command[looper].wr_here);
		if (g_shell.command[looper].rd_here > STDIN_FILENO)
			close(g_shell.command[looper].rd_here);
		looper++;
	}
	free(g_shell.command);
	rl_clear_history();
}

void	close_std(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
