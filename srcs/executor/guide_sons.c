/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide_sons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:15:24 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:15:24 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_cmd(size_t id)
{
	if (g_shell.command[id].argv != NULL && *g_shell.command[id].argv != NULL \
	&& **g_shell.command[id].argv != '\0' && \
	isbuiltin(*g_shell.command[id].argv) == TRUE)
		builtins(g_shell.command[id].argv);
	else if (g_shell.command[id].argv != NULL && \
	*g_shell.command[id].argv != NULL && **g_shell.command[id].argv != '\0')
		system_exec(g_shell.command[id].argv, g_shell.envp);
	else if (g_shell.command[id].argv != NULL && \
	*g_shell.command[id].argv != NULL && **g_shell.command[id].argv == '\0')
	{
		free_son();
		close_std();
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, "");
		free_son();
		close_std();
		exit(CMD_NOT_FOUND);
	}
}

void	guide_sons(int *pipe, size_t id)
{
	default_signals();
	if (g_shell.command[id].rd_here < STDIN_FILENO || \
	g_shell.command[id].wr_here < STDOUT_FILENO)
	{
		close(pipe[0]);
		close(pipe[1]);
		free_son();
		close_std();
		exit(EXIT_FAILURE);
	}
	open_redirect(pipe, id);
	close(pipe[0]);
	close(pipe[1]);
	execute_cmd(id);
}
