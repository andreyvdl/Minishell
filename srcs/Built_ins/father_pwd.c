/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:32 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:11:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	father_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror(ERR_PWD_PERROR);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	if (ft_strlen(cwd) > FT_PATHMAX)
	{
		ft_printf_fd(STDERR_FILENO, ERR_PWD_TOO_LONG, cwd, \
		strerror(FT_ENAMETOOLONG));
		free(cwd);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	ft_putstr(cwd);
	free(cwd);
	ft_putchar('\n');
	insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}
