#include "../../includes/minishell.h"

/* int change_directory(const char *path)
{
	char current_dir[256];

	getcwd(current_dir, sizeof(current_dir));
	if (chdir(path) == -1)
	{
		perror("cd");
		return (-1);
	}
	getcwd(current_dir, sizeof(current_dir));

	return (0);
}

int cd()
{
	char	*home_dir;
	char	**path;

	path = g_shell.command->argv;
	if (ft_matrixlen((const char **)path) <= 2)
	{
		if (path[1] == NULL)
		{
			home_dir = search(g_shell.hash, "HOME");
			if (home_dir == NULL)
			{
				perror("cd");
				return (-1);
			}
			return (change_directory(home_dir));
		}
		else
			return (change_directory(path[1]));
	}
	else
		return (ft_printf("to many args\n"));

	return (0);
} */

static void	fake_go_to_home(void)
{
	char	*home;

	home = search(g_shell.hash, "HOME");
	if (home == NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CD_HOME);
		free_son();
		exit(EXIT_FAILURE);
	}
	else if (ft_strlen(home) > FT_PATHMAX)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CD_TOO_LONG, home, \
		strerror(FT_ENAMETOOLONG));
		free_son();
		exit(EXIT_FAILURE);
	}
	free_son();
	exit(EXIT_SUCCESS);
}

static void	has_many_args(char **argv)
{
	if (*(argv + 1) != NULL && *(argv + 2) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CD_ARGS);
		free_son();
		exit(EXIT_FAILURE);
	}
}

static void	cd_is_directory(char **argv)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(*(argv + 1), &file_stat) == -1)
	{
		free_son();
		perror(ERR_STAT);
		exit(EXIT_FAILURE);
	}
	if (S_ISDIR(file_stat.st_mode))
		return ;
	ft_printf_fd(STDERR_FILENO, ERR_CD_DIR, *(argv + 1), strerror(FT_ENOTDIR));
	free_son();
	exit(EXIT_FAILURE);
}

void	ft_cd(char **argv)
{
	has_many_args(argv);
	if (*(argv + 1) == NULL || \
	(**(argv + 1) == '~' && *(*(argv + 1) + 1) == '\0'))
		fake_go_to_home();
	if (**(argv + 1) == '\0')
	{
		free_son();
		exit(EXIT_SUCCESS);
	}
	if (access(*(argv + 1), X_OK) == -1)
	{
		perror(ERR_CD_ACCESS);
		free_son();
		exit(EXIT_FAILURE);
	}
	cd_is_directory(argv);
	free_son();
	exit(EXIT_SUCCESS);
}
