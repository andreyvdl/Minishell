#include "../../includes/minishell.h"

static void	free_son_and_exit(void)
{
		ft_free_matrix(g_shell.LEXER_REST);
		ft_free_matrix(g_shell.REDIRECT_REST);
		free_hash(g_shell.hash);
		while (g_shell.id > 0)
		{
			if (g_shell.command[g_shell.id].(*argv) != NULL)
				ft_free_matrix(g_shell.command[g_shell.id].argv);
			// ! pai abriu, acho q o filho n tem q fechar if (g_shell.command[g_shell.id].wr_here > 0)
			// !close(g_shell.command[g_shell.id].wr_here);
			// !if (g_shell.command[g_shell.id].rd_here > 0)
			// !close(g_shell.command[g_shell.id].rd_here);
			free(g_shell.command[g_shell.id]);
			g_shell.id--;
		}
		exit(REDI_OK);
}

static void	remove_quotes_heredoc(char *limiter)
{
	while (*limiter)
	{
		if (*limiter == '\'')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
			while (*limiter != '\'')
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
		}
		else if (*limiter == '\"')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
			while (*limiter != '\"')
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
		}
		else
			limiter++;
	}
}

static int	without_expansions(char *limiter, t_command *son, size_t id)
{
	int		pid;
	int		status;
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		// heredoc_signals(); disable for now
		no_expansion_loop(limiter, son);
		free_son_and_exit();
	}
	waitpid(pid, &status, 0);
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
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		// heredoc_signals(); disable for now
		expansion_loop(limiter, son, id);
		free_son_and_exit();
	}
	waitpid(pid, &status, 0);
	if (status == SIGNAL_INT)
	{
		close(son[id].rd_here);
		son[id].rd_here = -130;
		unlink(HEREDOC_PATH);
		return (REDI_SIGNAL);
	}
	return (REDI_OK);
}

int	heredoc(char *limiter, t_command *son, size_t id)
{
	if (son[id].rd_here > -1)
		close(son[id].rd_here);
	son[id].rd_here = open(HEREDOC_PATH, HEREDOC, PERM_CREATE);
	if (son[id].rd_here == -1)
	{
		perror(ERR_HEREDOC);
		son[id].rd_here = -42;
		return (REDI_SIGNAL);
	}
	if (ft_strchr(limiter, '\'') != NULL || ft_strchr(limiter, '\"') != NULL)
	{
		remove_quotes_heredoc(limiter);
		return (without_expansions(limiter, son, id));
	}
	return (with_expansions(limiter, son, id));
}
