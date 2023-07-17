/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:17:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/17 14:18:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_son_and_exit(void)
{
	ft_free_matrix((void **)g_shell.pipeline_rest);
	ft_free_matrix((void **)g_shell.redirect_rest);
	ft_free_matrix((void **)g_shell.envp);
	free_hash(g_shell.hash);
	while (g_shell.id < g_shell.nbr_sons)
	{
		ft_free_matrix((void **)g_shell.command[g_shell.id].argv);
		if (g_shell.command[g_shell.id].wr_here > STDOUT_FILENO)
			close(g_shell.command[g_shell.id].wr_here);
		if (g_shell.command[g_shell.id].rd_here > STDIN_FILENO)
			close(g_shell.command[g_shell.id].rd_here);
		g_shell.id--;
	}
	free(g_shell.command);
	rl_clear_history();
	close_std();
	exit(REDI_OK);
}

static void	remove_quotes_heredoc(char *limiter)
{
	while (*limiter)
	{
		if (*limiter == '\'')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1) + 1);
			while (*limiter != '\'')
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1) + 1);
		}
		else if (*limiter == '\"')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1) + 1);
			while (*limiter != '\"')
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1) + 1);
		}
		else
			limiter++;
	}
}

static int	without_expansions(char *limiter, t_command *son, size_t id)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		heredoc_signals();
		no_expansion_loop(limiter, son, id);
		free_son_and_exit();
	}
	waitpid(pid, &status, NONE);
	if (status == SIGNAL_INT)
	{
		close(son[id].rd_here);
		unlink(HEREDOC_PATH);
		son[id].rd_here = -130;
		return (REDI_SIGNAL);
	}
	return (REDI_OK);
}

static int	with_expansions(char *limiter, t_command *son, size_t id)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		heredoc_signals();
		expansion_loop(limiter, son, id);
		free_son_and_exit();
	}
	waitpid(pid, &status, NONE);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 255)
	{
		close(son[id].rd_here);
		son[id].rd_here = SIGNAL_INT;
		unlink(HEREDOC_PATH);
		return (REDI_SIGNAL);
	}
	return (REDI_OK);
}

int	heredoc(char *limiter, t_command *son, size_t id)
{
	if (son[id].rd_here > STDIN_FILENO)
		close(son[id].rd_here);
	son[id].rd_here = open(HEREDOC_PATH, HEREDOC, PERM_CREATE);
	if (son[id].rd_here == -1)
	{
		perror(ERR_HEREDOC);
		son[id].rd_here = REDIRECT_ERROR;
		return (REDI_SIGNAL);
	}
	if (ft_strchr(limiter, '\'') != NULL || ft_strchr(limiter, '\"') != NULL)
	{
		remove_quotes_heredoc(limiter);
		return (without_expansions(limiter, son, id));
	}
	return (with_expansions(limiter, son, id));
}
