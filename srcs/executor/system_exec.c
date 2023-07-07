/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:16:07 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/27 16:16:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// file name too long 126

static void	permission_denied(char *path, char **binaries, char *temp)
{
	ft_free_matrix((void **)binaries);
	free(temp);
	free(path);
	free_son();
	perror(ERR_ACCESS);
	close_std();
	exit(EXEC_WENT_WRONG);
}

static char	*try_all_paths(char **binaries, char *temp)
{
	size_t	looper;
	char	*path;

	looper = 0;
	while (binaries[looper + 1] != NULL)
	{
		path = ft_strjoin(binaries[looper], temp);
		if (access(path, X_OK) != -1)
			return (path);
		free(path);
		path = NULL;
		looper++;
	}
	path = ft_strjoin(binaries[looper - 1], temp);
	if (access(path, F_OK) == -1)
	{
		free(path);
		path = NULL;
	}
	else if (access(path, X_OK) == -1)
		permission_denied(path, binaries, temp);
	return (path);
}

static char	*match_path(char *cmd)
{
	char	**binaries;
	char	*temp;
	char	*path;

	binaries = ft_split(search(g_shell.hash, "PATH"), ':');
	if (binaries == NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND_2, cmd);
		free_son();
		close_std();
		exit(CMD_NOT_FOUND);
	}
	temp = ft_strjoin("/", cmd);
	path = try_all_paths(binaries, temp);
	ft_free_matrix((void **)binaries);
	free(temp);
	if (path == NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, cmd);
		free_son();
		close_std();
		exit(CMD_NOT_FOUND);
	}
	return (path);
}

static char	*find_path(char *cmd)
{
	char	*temp;
	char	*cwd;
	char	*path;

	if (ft_strncmp(cmd, "/", 1) == 0)
		path = ft_strdup(cmd);
	else if (ft_strncmp(cmd, "./", 2) == 0 || strncmp(cmd, "../", 3) == 0)
	{
		cwd = getcwd(NULL, 0);
		temp = ft_strjoin(cwd, "/");
		free(cwd);
		path = ft_strjoin(temp, cmd);
		free(temp);
	}
	else
		path = match_path(cmd);
	execution_check(path);
	return (path);
}

void	system_exec(char **old_argv, char **old_envp)
{
	char	**argv;
	char	**envp;
	char	*path;

	path = find_path(old_argv[0]);
	argv = ft_matrixdup(old_argv);
	envp = ft_matrixdup(old_envp);
	free_son();
	execve(path, argv, envp);
	perror(ERR_EXECVE);
	ft_free(path);
	ft_free_matrix((void **)argv);
	ft_free_matrix((void **)envp);
	close_std();
	exit(EXEC_WENT_WRONG);
}
