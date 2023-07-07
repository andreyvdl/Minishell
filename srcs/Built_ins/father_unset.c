/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:07:46 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:07:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	can_remove_node(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (FALSE);
	while (ft_isalnum(*arg) || *arg == '_')
		arg++;
	if (*arg != '\0')
		return (FALSE);
	return (TRUE);
}

static void	remove_these(char **argv)
{
	int	printed;

	argv++;
	printed = 0;
	while (*argv != NULL)
	{
		if (can_remove_node(*argv) == FALSE)
			printed = ft_printf_fd(STDERR_FILENO, ERR_UNSET_INVALID, *argv);
		else
			remove_node(g_shell.hash, *argv);
		argv++;
	}
	if (printed != 0)
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
	else
		insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}

void	father_unset(char **argv)
{
	if (*(argv + 1) != NULL)
		remove_these(argv);
}
