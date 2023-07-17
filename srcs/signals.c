/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:29:00 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/17 14:19:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	re_print_prompt(int sig)
{
	if (sig == SIGINT)
	{
		insert_node(g_shell.hash, STATUS_CODE, "130");
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	exit_heredoc(int sig)
{
	ft_putchar('\n');
	ft_free_matrix((void **)g_shell.pipeline_rest);
	ft_free_matrix((void **)g_shell.redirect_rest);
	ft_free_matrix((void **)g_shell.envp);
	while (g_shell.id < g_shell.nbr_sons)
	{
		if (*g_shell.command[g_shell.id].argv != NULL)
			ft_free_matrix((void **)g_shell.command[g_shell.id].argv);
		if (g_shell.command[g_shell.id].wr_here > STDOUT_FILENO)
			close(g_shell.command[g_shell.id].wr_here);
		if (g_shell.command[g_shell.id].rd_here > STDIN_FILENO)
			close(g_shell.command[g_shell.id].rd_here);
		g_shell.id--;
	}
	free(g_shell.command);
	free_hash(g_shell.hash);
	rl_clear_history();
	close_std();
	if (sig == SIGINT)
		exit(REDI_SIGNAL);
	exit(REDI_OK);
}

void	default_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGPIPE, SIG_IGN);
}

void	heredoc_signals(void)
{
	signal(SIGINT, exit_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	set_up_signals(void)
{
	signal(SIGINT, re_print_prompt);
	signal(SIGQUIT, SIG_IGN);
}
