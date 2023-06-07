#include "../../includes/minishell.h"

/* void	pwd()
{
	char	path[4096];

	if (getcwd(path, sizeof(path)) != NULL)
		printf("%s\n", path);
	else
		perror("pwd");
} */

void	ft_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror(ERR_PWD_PERROR);
		free_son();
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(cwd) > FT_PATHMAX)
	{
		ft_printf_fd(STDERR_FILENO, ERR_PWD_TOO_LONG, cwd, \
		strerror(FT_ENAMETOOLONG));
		free(cwd);
		free_son();
		exit(EXIT_FAILURE);
	}
	ft_putstr(cwd);
	free(cwd);
	free_son();
	exit(EXIT_SUCCESS);
}
