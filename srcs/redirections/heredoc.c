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

static void	remove_quotes(char *limiter)
{
	while (*limiter)
	{
		if (*limiter == '\'')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
			while (*limiter != '\'' && *limiter)
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
		}
		else if (*limiter == '\"')
		{
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
			while (*limiter != '\"' && *limiter)
				limiter++;
			ft_memmove(limiter, limiter + 1, ft_strlen(limiter + 1));
		}
	}
}

static int	without_expansions(char *limiter, t_command *son)
{
	int		pid;
	int		status;
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		heredoc_signals();
		no_expansion_loop(limiter, son);
		free_son_and_exit();
	}
	waitpid(pid, &status, 0);
	if (status == SIGNAL_INT)
	{
		close(son->rd_here);
		unlink(HEREDOC_FILE);
		return (REDI_SIGNAL);
	}
	return (REDI_OK);
}

static int	with_expansions

int	heredoc(char *limiter, t_command *son)
{
	son->rd_here = open(HEREDOC_FILE, O_RDWR | O_CREAT | O_TRUNC, PERM_CREATE);
	if (*limiter == '\"' || *limiter == '\'')
	{
		remove_quotes(limiter);
		return (without_expansions(limiter, son));
	}
	return (with_expansions(limiter, son));
}
