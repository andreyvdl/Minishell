/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:15:51 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/13 13:51:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_directory(char *path)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(path, &file_stat) == -1)
	{
		free_son();
		free(path);
		perror(ERR_STAT);
		close_std();
		exit(CMD_NOT_FOUND);
	}
	if (S_ISDIR(file_stat.st_mode))
	{
		free_son();
		free(path);
		ft_printf_fd(STDERR_FILENO, ERR_EXEC_DIR, strerror(FT_EISDIR));
		close_std();
		exit(EXEC_WENT_WRONG);
	}
}
