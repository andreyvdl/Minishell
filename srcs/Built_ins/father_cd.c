/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:12:52 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:12:53 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_cwd(char *cwd)
{
	if (cwd != NULL)
		free(cwd);
}

static void	go_to_home(void)
{
	char	*home;
	char	*cwd;

	home = search(g_shell.hash, "HOME");
	if (home == NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CD_HOME);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	cwd = getcwd(NULL, 0);
	if (chdir(home) == -1)
	{
		perror(ERR_CHDIR);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		free_cwd(cwd);
		return ;
	}
	else if (cwd != NULL)
	{
		insert_node(g_shell.hash, "OLDPWD", cwd);
		free(cwd);
	}
	insert_node(g_shell.hash, "PWD", home);
	insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}

static int	has_many_args(char **argv)
{
	if (*(argv + 1) != NULL && *(argv + 2) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CD_ARGS);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return (TRUE);
	}
	return (FALSE);
}

static void	change_directory(char *path)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		perror(ERR_CHDIR);
		free_cwd(cwd);
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	else if (cwd != NULL)
	{
		insert_node(g_shell.hash, "OLDPWD", cwd);
		free(cwd);
	}
	cwd = getcwd(NULL, 0);
	insert_node(g_shell.hash, "PWD", cwd);
}

void	father_cd(char **argv)
{
	if (has_many_args(argv) == TRUE)
		return ;
	else if (*(argv + 1) == NULL || \
	(**(argv + 1) == '~' && *(*(argv + 1) + 1) == '\0'))
	{
		go_to_home();
		return ;
	}
	else if (**(argv + 1) == '\0')
	{
		insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
		return ;
	}
	change_directory(*(argv + 1));
}
