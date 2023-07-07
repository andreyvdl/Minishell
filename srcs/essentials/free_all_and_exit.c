/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:04:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:04:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all_and_exit(t_hash *hash)
{
	ft_putstr("exit\n");
	free_hash(hash);
	rl_clear_history();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	if (access(HEREDOC_PATH, F_OK) != -1)
		unlink(HEREDOC_PATH);
	exit(0);
}
