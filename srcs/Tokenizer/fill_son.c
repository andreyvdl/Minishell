/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_son.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	skip_redirect(char **cmd)
{
	(*cmd) += 2;
	while (**cmd == -7)
		(*cmd)++;
	while (**cmd != -7 && **cmd != '\0')
		(*cmd)++;
}

static void	copy_args(char **argv, char *cmd)
{
	size_t	index;
	size_t	arg_index;

	arg_index = 0;
	while (cmd != NULL && *cmd != '\0')
	{
		if (*cmd == '<' || *cmd == '>')
			skip_redirect(&cmd);
		else if (*cmd == -7)
			cmd++;
		else
		{
			index = 0;
			while (cmd[index] != '\0' && cmd[index] != -7)
				index++;
			argv[arg_index] = ft_substr(cmd, 0, index);
			arg_index++;
			ft_memmove(cmd, cmd + index, ft_strlen(cmd + index) + 1);
		}
	}
	argv[arg_index] = NULL;
}

static size_t	count_args(char *cmd)
{
	size_t	nbr_args;

	nbr_args = 0;
	while (*cmd != '\0')
	{
		if (*cmd == '<' || *cmd == '>')
			skip_redirect(&cmd);
		else if (*cmd == -7)
			cmd++;
		else
		{
			nbr_args++;
			while (*cmd != '\0' && *cmd != -7)
				cmd++;
		}
	}
	return (nbr_args);
}

static void	expand_args(char **argv)
{
	size_t	index;
	char	*temp;

	index = 0;
	while (argv[index] != NULL)
	{
		temp = remove_quote_or_expand(argv[index]);
		if (argv[index] != temp)
		{
			free(argv[index]);
			argv[index] = temp;
		}
		index++;
	}
}

int	fill_son_orders(t_command *son_struct, char *cmd)
{
	int		status;
	char	**redirect;
	size_t	nbr_args;

	nbr_args = count_args(cmd);
	status = REDI_OK;
	son_struct[g_shell.id].argv = (char **)ft_calloc(nbr_args + 1, \
	sizeof(char *));
	copy_args(son_struct[g_shell.id].argv, cmd);
	expand_args(son_struct[g_shell.id].argv);
	redirect = ft_split(cmd, -7);
	son_struct[g_shell.id].wr_here = STDOUT_FILENO;
	son_struct[g_shell.id].rd_here = STDIN_FILENO;
	if (redirect && *redirect)
		status = redirection(redirect, son_struct, g_shell.id);
	ft_free_matrix((void **)redirect);
	return (status);
}
