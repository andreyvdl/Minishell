/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:12:00 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/10 13:53:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	env_is_directory(char **argv)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(*(argv + 1), &file_stat) == -1)
	{
		free_son();
		perror(ERR_STAT);
		close_std();
		exit(EXIT_FAILURE);
	}
	if (S_ISDIR(file_stat.st_mode))
		return (TRUE);
	return (FALSE);
}

static void	print_vars_env(void)
{
	t_node	*node;
	size_t	looper;

	looper = 0;
	while (looper < HASH_SIZE)
	{
		node = g_shell.hash->list[looper];
		while (node != NULL)
		{
			if (*node->key != '?' && node->value != NULL)
				ft_printf_ln("%s=%s", node->key, node->value);
			node = node->next;
		}
		looper++;
	}
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}

void	ft_env(char **argv)
{
	if (*(argv + 1) != NULL && env_is_directory(argv) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
		free_son();
		close_std();
		exit(EXEC_WENT_WRONG);
	}
	else if (*(argv + 1) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_ENV_ARGS);
		free_son();
		close_std();
		exit(CMD_NOT_FOUND);
	}
	print_vars_env();
}
