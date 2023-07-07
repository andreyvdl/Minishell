/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:07:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:07:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	just_free(void)
{
	ft_free_matrix((void **)g_shell.command->argv);
	if (g_shell.command->wr_here > STDOUT_FILENO)
		close(g_shell.command->wr_here);
	if (g_shell.command->rd_here > STDIN_FILENO)
		close(g_shell.command->rd_here);
	free(g_shell.command);
	ft_free_matrix((void **)g_shell.envp);
	free_hash(g_shell.hash);
	rl_clear_history();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	if (access(HEREDOC_PATH, F_OK) != -1)
		unlink(HEREDOC_PATH);
}

static int	only_numbers(char *arg)
{
	while ((*arg == '\t' || *arg == ' ') && *arg != '\0')
		arg++;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (ft_isdigit(*arg) && *arg != '\0')
		arg++;
	while ((*arg == '\t' || *arg == ' ') && *arg != '\0')
		arg++;
	if (*arg != '\0')
		return (FALSE);
	return (TRUE);
}

static void	validate_exit(char *arg)
{
	ssize_t	nbr;

	if (only_numbers(arg) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_NUMBER, arg);
		just_free();
		exit(FT_EXIT_ERROR);
	}
	else if (number_big(arg) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_NUMBER, arg);
		just_free();
		exit(FT_EXIT_ERROR);
	}
	nbr = ft_atoll(arg);
	just_free();
	exit(nbr);
}

void	father_exit(char **argv)
{
	if (*(argv + 1) != NULL && *(argv + 2) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_ARGS);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	else if (*(argv + 1) == NULL)
	{
		just_free();
		exit(EXIT_SUCCESS);
	}
	validate_exit(*(argv + 1));
}
