#include "../../includes/minishell.h"

int change_directory(const char *path)
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
}