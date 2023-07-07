/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:10:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:10:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_vars_export(void)
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
				ft_printf_ln(EXPORT_PRINT_VALUE, node->key, node->value);
			else if (*node->key != '?')
				ft_printf_ln(EXPORT_PRINT_VAR, node->key);
			node = node->next;
		}
		looper++;
	}
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}

static int	fake_add_var(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (FALSE);
	while ((ft_isalnum(*arg) || *arg == '_') && *arg != '\0')
		arg++;
	if (*arg != '=' && *arg != '\0')
		return (FALSE);
	return (TRUE);
}

static void	add_new_vars(char **argv)
{
	int	printed;

	argv++;
	printed = 0;
	while (*argv != NULL)
	{
		if (fake_add_var(*argv) == FALSE)
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

void	ft_export(char **argv)
{
	if (*(argv + 1) == NULL)
		print_vars_export();
	add_new_vars(argv);
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}
