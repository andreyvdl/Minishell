/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:17:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:17:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_directory_input(char *filename)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	stat(filename, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		return (TRUE);
	return (FALSE);
}

static int	open_check(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		perror(ERR_READING);
		return (REDI_ERR);
	}
	else if (is_directory_input(filename) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_INPUT_DIR, strerror(FT_EISDIR));
		return (REDI_ERR);
	}
	else if (filename_too_big(filename) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_INPUT_DIR, strerror(FT_ENAMETOOLONG));
		return (REDI_ERR);
	}
	return (REDI_OK);
}

int	redirect_input(char *filename, t_command *son, size_t id)
{
	char	*temp;
	int		file_des;

	temp = remove_quote_or_expand(filename);
	if (open_check(temp) == REDI_ERR)
	{
		if (temp != filename)
			free(temp);
		if (son[id].rd_here > STDIN_FILENO)
			close(son[id].rd_here);
		son[id].rd_here = REDIRECT_ERROR;
		return (REDI_ERR);
	}
	file_des = open(temp, O_RDONLY);
	if (temp != filename)
		free(temp);
	if (son[id].rd_here > STDIN_FILENO)
		close(son[id].rd_here);
	son[id].rd_here = file_des;
	return (REDI_OK);
}
