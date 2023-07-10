/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:09:10 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/10 13:53:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	fake_remove(char *arg)
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
		if (fake_remove(*argv) == FALSE)
			printed = ft_printf_fd(STDERR_FILENO, ERR_UNSET_INVALID, *argv);
		argv++;
	}
	if (printed != 0)
	{
		free_son();
		close_std();
		exit(EXIT_FAILURE);
	}
}

void	ft_unset(char **argv)
{
	if (*(argv + 1) != NULL)
		remove_these(argv);
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}
