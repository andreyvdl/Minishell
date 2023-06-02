#include "../../includes/minishell.h"

// file name too long 126
// command not found 127
// permission denied 126

static void	is_directory(char *path)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	stat(path, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		free_son();
		free(path);
		ft_printf_fd(STDERR_FILENO, ERR_EXEC_DIR, strerror(21));
		exit(IS_A_DIRECTORY);
	}
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
		path = 
	check(path);
	return (path);
}

void	system_exec(char **old_argv, char **old_envp, size_t id)
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
	free(path);
	ft_free_matrix(argv);
	ft_free_matrix(envp);
	exit(SOMETHING_WENT_WRONG);
}
