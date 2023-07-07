/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:09:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:09:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

static void	son_exit(char *arg)
{
	ssize_t	nbr;

	if (only_numbers(arg) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_NUMBER, arg);
		free_son();
		exit(FT_EXIT_ERROR);
	}
	else if (number_big(arg) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_NUMBER, arg);
		free_son();
		exit(FT_EXIT_ERROR);
	}
	nbr = ft_atoll(arg);
	free_son();
	exit(nbr);
}

void	ft_exit(char **argv)
{
	if (*(argv + 1) != NULL && *(argv + 2) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_EXIT_ARGS);
		free_son();
		exit(EXIT_FAILURE);
	}
	else if (*(argv + 1) == NULL)
	{
		free_son();
		exit(EXIT_SUCCESS);
	}
	son_exit(*(argv + 1));
}
