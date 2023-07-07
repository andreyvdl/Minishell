/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:15:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:15:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execution_check(char *path)
{
	if (filename_too_big(path) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_FILENAME, strerror(FT_ENAMETOOLONG));
		free(path);
		free_son();
		close_std();
		exit(EXEC_WENT_WRONG);
	}
	is_directory(path);
	if (access(path, F_OK) == -1)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, path);
		free(path);
		free_son();
		close_std();
		exit(CMD_NOT_FOUND);
	}
	else if (access(path, X_OK) == -1)
	{
		free(path);
		free_son();
		perror(ERR_ACCESS);
		close_std();
		exit(EXEC_WENT_WRONG);
	}
}
