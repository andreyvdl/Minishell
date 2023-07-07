/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:18:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:18:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redirect_output_append(char *filename, t_command *son, size_t id)
{
	char	*temp;
	int		file_des;

	temp = remove_quote_or_expand(filename);
	file_des = open(temp, APPEND, PERM_CREATE);
	if (temp != filename)
		free(temp);
	if (file_des == -1 || filename_too_big(temp) == TRUE)
	{
		if (son[id].wr_here > STDOUT_FILENO)
			close(son[id].wr_here);
		son[id].wr_here = REDIRECT_ERROR;
		perror(ERR_WRITING);
		return (REDI_ERR);
	}
	if (son[id].wr_here > STDOUT_FILENO)
		close(son[id].wr_here);
	son[id].wr_here = file_des;
	return (REDI_OK);
}
